// Copyright (c) 2022 ChenJun
// Licensed under the Apache-2.0 License.

#include <tf2/LinearMath/Quaternion.h>

#include <auto_aim_interfaces/msg/detail/gimbal_cmd__struct.hpp>
#include "rm_decision_interfaces/msg/refree.hpp"
#include <rclcpp/logging.hpp>
#include <rclcpp/qos.hpp>
#include <rclcpp/utilities.hpp>
#include <serial_driver/serial_driver.hpp>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>
#include<chrono>
#include<thread>

// C++ system
#include <cstdint>
#include <functional>
#include <map>
#include <memory>
#include <string>
#include <vector>

#include "rm_serial_driver/crc.hpp"
#include "rm_serial_driver/packet.hpp"
#include "rm_serial_driver/rm_serial_driver.hpp"

// 决策依赖库
// #include "decision_moudle/msg/hp.hpp"
// #include "decision_moudle/msg/site.hpp"

namespace rm_serial_driver
{
RMSerialDriver::RMSerialDriver(const rclcpp::NodeOptions & options)
: Node("rm_serial_driver", options),
  owned_ctx_{new IoContext(2)},
  serial_driver_{new drivers::serial_driver::SerialDriver(*owned_ctx_)}
{
  RCLCPP_INFO(get_logger(), "Start RMSerialDriver!");

  getParams();

  // Publisher: publish referee data (robot HP) to /refree for decision node
  refree_pub_ = this->create_publisher<rm_decision_interfaces::msg::Refree>("/refree_data", 10);

  // TF broadcaster
  timestamp_offset_ = this->declare_parameter("timestamp_offset", 0.0);
  tf_broadcaster_ = std::make_unique<tf2_ros::TransformBroadcaster>(*this);

  // Create Publisher
  latency_pub_ = this->create_publisher<std_msgs::msg::Float64>("/latency", 10);
  marker_pub_ = this->create_publisher<visualization_msgs::msg::Marker>("/aiming_point", 10);

  // site_pub = this->create_publisher<decision_moudle::msg::Site>("/incident", 10);
  // health_pub = this->create_publisher<decision_moudle::msg::Hp>("/allhealth", 10);
  // Detector parameter clients (support multiple detector nodes)
  detector_node_names_ = this->declare_parameter<std::vector<std::string>>(
    "detector_node_names",
    std::vector<std::string>{"armor_detector_first", "armor_detector_second"});
  for (const auto & name : detector_node_names_) {
    detector_param_clients_[name] = std::make_shared<rclcpp::AsyncParametersClient>(this, name);
    last_set_color_[name] = -1;  // not set yet
  }

  // Tracker reset service client
  reset_tracker_client_ = this->create_client<std_srvs::srv::Trigger>("/tracker/reset");

  try {
    serial_driver_->init_port(device_name_, *device_config_);
    if (!serial_driver_->port()->is_open()) {
      serial_driver_->port()->open();
      receive_thread_ = std::thread(&RMSerialDriver::receiveData, this);
    }
  } catch (const std::exception & ex) {
    RCLCPP_ERROR(
    get_logger(), "Error creating serial port: %s - %s", device_name_.c_str(), ex.what());

    throw ex;
  }

  aiming_point_.header.frame_id = "odom";
  aiming_point_.ns = "aiming_point";
  aiming_point_.type = visualization_msgs::msg::Marker::SPHERE;
  aiming_point_.action = visualization_msgs::msg::Marker::ADD;
  aiming_point_.scale.x = aiming_point_.scale.y = aiming_point_.scale.z = 0.12;
  aiming_point_.color.r = 1.0;
  aiming_point_.color.g = 1.0;
  aiming_point_.color.b = 1.0;
  aiming_point_.color.a = 1.0;
  aiming_point_.lifetime = rclcpp::Duration::from_seconds(0.1);

  // Create Subscription
  gimbal_cmd_sub_ = this->create_subscription<auto_aim_interfaces::msg::GimbalCmd>(
    "/solver/cmd_gimbal", rclcpp::SensorDataQoS(),
    std::bind(&RMSerialDriver::sendData, this, std::placeholders::_1));

  cmd_vel_sub_ = this->create_subscription<geometry_msgs::msg::Twist>(
    "/cmd_vel", rclcpp::SensorDataQoS(),

    [this](const geometry_msgs::msg::Twist::SharedPtr msg) {
      try{
        CmdVelPacket packet;
        packet.linear_x = msg->linear.x;
        packet.linear_y = msg->linear.y;
        crc16::Append_CRC16_Check_Sum(reinterpret_cast<uint8_t *>(&packet), sizeof(packet));

        std::vector<uint8_t> data = cmd_toVector(packet);

        // 打印导航数据详细信息
        RCLCPP_WARN(get_logger(), "===== Sending Navigation (cmd_vel) Data =====");
        RCLCPP_WARN(get_logger(), "Linear X: %.4f m/s", packet.linear_x);
        RCLCPP_WARN(get_logger(), "Linear Y: %.4f m/s", packet.linear_y);
        RCLCPP_WARN(get_logger(), "Checksum: 0x%04X", packet.checksum);
        RCLCPP_WARN(get_logger(), "Packet Size: %zu bytes", data.size());
        
        // 打印原始数据包（十六进制）
        std::string hex_data = "Raw Data: ";
        for (size_t i = 0; i < data.size(); ++i) {
          char hex_str[4];
          snprintf(hex_str, sizeof(hex_str), "%02X ", data[i]);
          hex_data += hex_str;
        }
        RCLCPP_WARN(get_logger(), "%s", hex_data.c_str());
        RCLCPP_WARN(get_logger(), "==========================================");
        
        serial_driver_->port()->send(data);
      } catch (const std::exception & ex) {
        RCLCPP_ERROR(get_logger(), "Error while sending cmd_vel data: %s", ex.what());
        reopenPort();
      }
    });
}

RMSerialDriver::~RMSerialDriver()
{
  if (receive_thread_.joinable()) {
    receive_thread_.join();
  }

  if (serial_driver_->port()->is_open()) {
    serial_driver_->port()->close();
  }

  if (owned_ctx_) {
    owned_ctx_->waitForExit();
  }
}

void RMSerialDriver::receiveData()
{
  std::vector<uint8_t> header(1);
  std::vector<uint8_t> data;

  // 用于提取前11位数据的掩码
  // uint32_t mask = 0x7FF;
  // uint32_t extracted_bits;
  // uint16_t purchase_bullet;
  // uint8_t team = -1;
  while (rclcpp::ok()) {
    try {
      serial_driver_->port()->receive(header);
    static auto last_time = std::chrono::steady_clock::now();

    auto now = std::chrono::steady_clock::now();

    double dt = std::chrono::duration<double>(now - last_time).count(); // 秒
    last_time = now;
        double freq = (dt > 0) ? (1.0 / dt) : 0.0;
      if (header[0] == 0x5A)        // 自瞄
      {
        (void)freq;
    // 1. 先调整 data 尺寸
    //data.resize(sizeof(ReceivePacket) - 2); // 减去 checksum 的两个字节

    // 2. 从串口接收数据
    serial_driver_->port()->receive(data);

    // 3. 在数据前面加上 header
     data.insert(data.begin(), header[0]);

    // 4. 扩展 data 给 checksum 两个字节
    data.resize(sizeof(ReceivePacket));

    // 5. 计算 CRC 并追加到末尾
    crc16::Append_CRC16_Check_Sum(data.data(), data.size());

    // 6. 转换为结构体
ReceivePacket packet;
packet.header = data[0];
packet.detect_color = data[1] & 0x01;
packet.reset_tracker = (data[1] >> 1) & 0x01;
packet.reserved = (data[1] >> 2) & 0x3F;

// 小端解析 float
packet.roll  = *reinterpret_cast<float*>(&data[2]);
packet.yaw = *reinterpret_cast<float*>(&data[8]);
packet.pitch = *reinterpret_cast<float*>(&data[12]);
packet.reserved2 = *reinterpret_cast<uint16_t*>(&data[14]);

  // 新增保留位 data[14] data[15]
  packet.checksum = *reinterpret_cast<uint16_t*>(&data[16]);


//  printf("packet.header = 0x%X\n", packet.header);
//  printf("packet.detect_color = %u\n", packet.detect_color);
//  printf("packet.reset_tracker = %u\n", packet.reset_tracker);
//  printf("packet.reserved = %u\n", packet.reserved);
  // printf("packet.roll = %f\n,freq = %.2f Hz\n", packet.roll,freq);

 
// printf("packet.checksum = 0x%X\n", packet.checksum);
//         printf("Receive Data: %zu\n",sizeof(packet));
//        for (size_t i = 0; i < data.size(); ++i) {
//     printf("%02X ", data[i]);
// }
// printf("\n");

bool crc_ok = crc16::Verify_CRC16_Check_Sum(data.data(), data.size());
//  printf("CRC check: %s\n", crc_ok ? "PASS" : "FAIL");
        if (crc_ok) {
          // Update desired detect_color and attempt to push to detectors
          if (packet.detect_color != previous_receive_color_) {
            previous_receive_color_ = packet.detect_color;
          }
          setParam(rclcpp::Parameter("detect_color", static_cast<int>(previous_receive_color_)));

          if (packet.reset_tracker) {
            resetTracker();
          }
          // packet.roll = packet.roll;
          // packet.pitch = packet.pitch ;
          // packet.yaw = packet.yaw ;  
          // packet.roll = packet.roll * (180.0 / M_PI);
          // packet.pitch = packet.pitch *(180.0 / M_PI);
          // packet.yaw = packet.yaw * (180.0 / M_PI);  
  // printf("packet.pitch = %f\n", packet.pitch);
  // printf("packet.yaw = %f\n", packet.yaw);
          geometry_msgs::msg::TransformStamped t;
          timestamp_offset_ = this->get_parameter("timestamp_offset").as_double();
          t.header.stamp = this->now();
          t.header.frame_id = "odom";
          t.child_frame_id = "gimbal_link";
          tf2::Quaternion q;
          q.setRPY(packet.roll, packet.pitch, packet.yaw);
          t.transform.rotation = tf2::toMsg(q);
          tf_broadcaster_->sendTransform(t);

          //  if (packet.detect_color == 1)
          //    team = 0;
          //   else
          //    team = 1;

          if (true) {
            aiming_point_.header.stamp = this->now();
            aiming_point_.pose.position.x = 0.0;
            aiming_point_.pose.position.y = 0.0;
            aiming_point_.pose.position.z = 0.0;
            // aiming_point_.pose.position.x = packet.aim_x;
            // aiming_point_.pose.position.y = packet.aim_y;
            // aiming_point_.pose.position.z = packet.aim_z;
            marker_pub_->publish(aiming_point_);
            //RCLCPP_WARN(get_logger(), "CRC true");
          }
        } else {

          RCLCPP_ERROR(get_logger(), "CRC error!");
        }
      } 
      else if (header[0] == 0xA6)   // 导航决策
      {
      	// RCLCPP_INFO(get_logger(), "gggggggggggggggg");
        data.resize(sizeof(NavPacket) - 1);
        serial_driver_->port()->receive(data);
        data.insert(data.begin(), header[0]);
        NavPacket nav_packet = nav_fromVector(data);
        // CRC 校验
        bool crc_ok = crc16::Verify_CRC16_Check_Sum(reinterpret_cast<const uint8_t*>(&nav_packet), sizeof(nav_packet));
        if (true || crc_ok) 
        {
        // 数据包有效，处理数据
          // 读取当前血量（NavPacket 中为 uint16_t）
          uint16_t current_HP = nav_packet.current_HP;
          
          // // 打印导航数据详细信息
          // RCLCPP_WARN(get_logger(), "===== Received Navigation (0xA6) Data =====");
          // RCLCPP_WARN(get_logger(), "Header: 0x%02X", nav_packet.header);
          // RCLCPP_WARN(get_logger(), "Current Robot HP: %u", current_HP);
          // RCLCPP_WARN(get_logger(), "Checksum: 0x%04X (Valid: %s)", 
          //            nav_packet.checksum, crc_ok ? "YES" : "NO");
          // RCLCPP_WARN(get_logger(), "Packet Size: %zu bytes", sizeof(nav_packet));
          
          // // 打印原始数据包（十六进制）
          // std::string hex_data = "Raw Data: ";
          // const uint8_t* raw_data = reinterpret_cast<const uint8_t*>(&nav_packet);
          // for (size_t i = 0; i < sizeof(nav_packet); ++i) {
          //   char hex_str[4];
          //   snprintf(hex_str, sizeof(hex_str), "%02X ", raw_data[i]);
          //   hex_data += hex_str;
          // }
          // RCLCPP_WARN(get_logger(), "%s", hex_data.c_str());
          // RCLCPP_WARN(get_logger(), "==========================================");
          
          if (refree_pub_) {
            rm_decision_interfaces::msg::Refree ref_msg;
            ref_msg.robot_hp = current_HP;
            refree_pub_->publish(ref_msg);
          }
        } 

        else 
        {
          RCLCPP_ERROR(get_logger(), "CRC error!");
        }
      }
      
      else {
        // RCLCPP_WARN_THROTTLE(get_logger(), *get_clock(), 20, "Invalid header: %02X", header[0]);
      }
    } catch (const std::exception & ex) {
      RCLCPP_ERROR_THROTTLE(
        get_logger(), *get_clock(), 20, "Error while receiving data: %s", ex.what());
      reopenPort();
    }
  }
}

void RMSerialDriver::sendData(const auto_aim_interfaces::msg::GimbalCmd::SharedPtr msg)
{
  const static std::map<std::string, uint8_t> id_unit8_map{
    {"", 0},  {"outpost", 0}, {"1", 1}, {"1", 1},     {"2", 2},
    {"3", 3}, {"4", 4},       {"5", 5}, {"guard", 6}, {"base", 7}};

  try {
    SendPacket packet;
    // packet.tracking = msg->tracking;
    // packet.id = id_unit8_map.at(msg->id);
    // packet.armors_num = msg->armors_num;
    // packet.x = msg->position.x;
    // packet.y = msg->position.y;
    // packet.z = msg->position.z;
    // packet.yaw = msg->yaw;
    // packet.vx = msg->velocity.x;
    // packet.vy = msg->velocity.y;
    // packet.vz = msg->velocity.z;
    // packet.v_yaw = msg->v_yaw;
    // packet.r1 = msg->radius_1;
    // packet.r2 = msg->radius_2;
    // packet.dz = msg->dz;
    // packet.pitch = msg->pitch;
    packet.pitch_diff = msg->pitch_diff;
    // packet.yaw = msg->yaw;
    packet.yaw_diff = msg->yaw_diff;
    //packet.distance = msg->distance;
    packet.fire_advice = msg->fire_advice;
    crc16::Append_CRC16_Check_Sum(reinterpret_cast<uint8_t *>(&packet), sizeof(packet));

    std::vector<uint8_t> data = toVector(packet);

   
    serial_driver_->port()->send(data);
//std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    std_msgs::msg::Float64 latency;
    latency.data = (this->now() - msg->header.stamp).seconds() * 1000.0;
    RCLCPP_INFO_STREAM(get_logger(), "Total latency: " + std::to_string(latency.data) + "ms");
    
    latency_pub_->publish(latency);
  } catch (const std::exception & ex) {
    RCLCPP_ERROR(get_logger(), "Error while sending auto_aim data: %s", ex.what());
    reopenPort();
  }
}

void RMSerialDriver::getParams()
{
  using FlowControl = drivers::serial_driver::FlowControl;
  using Parity = drivers::serial_driver::Parity;
  using StopBits = drivers::serial_driver::StopBits;

  uint32_t baud_rate{};
  auto fc = FlowControl::NONE;
  auto pt = Parity::NONE;
  auto sb = StopBits::ONE;

  try {
    device_name_ = declare_parameter<std::string>("device_name", "/dev/ttyUSB0");
  } catch (rclcpp::ParameterTypeException & ex) {
    RCLCPP_ERROR(get_logger(), "The device name provided was invalid");
    throw ex;
  }

  try {
    baud_rate = declare_parameter<int>("baud_rate", 0);
  } catch (rclcpp::ParameterTypeException & ex) {
    RCLCPP_ERROR(get_logger(), "The baud_rate provided was invalid");
    throw ex;
  }

  try {
    const auto fc_string = declare_parameter<std::string>("flow_control", "");

    if (fc_string == "none") {
      fc = FlowControl::NONE;
    } else if (fc_string == "hardware") {
      fc = FlowControl::HARDWARE;
    } else if (fc_string == "software") {
      fc = FlowControl::SOFTWARE;
    } else {
      throw std::invalid_argument{
        "The flow_control parameter must be one of: none, software, or hardware."};
    }
  } catch (rclcpp::ParameterTypeException & ex) {
    RCLCPP_ERROR(get_logger(), "The flow_control provided was invalid");
    throw ex;
  }

  try {
    const auto pt_string = declare_parameter<std::string>("parity", "");

    if (pt_string == "none") {
      pt = Parity::NONE;
    } else if (pt_string == "odd") {
      pt = Parity::ODD;
  } }catch (rclcpp::ParameterTypeException & ex) {
    RCLCPP_ERROR(get_logger(), "The parity provided was invalid");
    throw ex;
  }

  try {
    const auto sb_string = declare_parameter<std::string>("stop_bits", "");

    if (sb_string == "1" || sb_string == "1.0") {
      sb = StopBits::ONE;
    } else if (sb_string == "1.5") {
      sb = StopBits::ONE_POINT_FIVE;
    } else if (sb_string == "2" || sb_string == "2.0") {
      sb = StopBits::TWO;
    } else {
      throw std::invalid_argument{"The stop_bits parameter must be one of: 1, 1.5, or 2."};
    }
  } catch (rclcpp::ParameterTypeException & ex) {
    RCLCPP_ERROR(get_logger(), "The stop_bits provided was invalid");
    throw ex;
  }

  device_config_ =
    std::make_unique<drivers::serial_driver::SerialPortConfig>(baud_rate, fc, pt, sb);
}

void RMSerialDriver::reopenPort()
{
  RCLCPP_WARN(get_logger(), "Attempting to reopen port");
  try {
    if (serial_driver_->port()->is_open()) {
      serial_driver_->port()->close();
    }
    serial_driver_->port()->open();
    RCLCPP_INFO(get_logger(), "Successfully reopened port");
  } catch (const std::exception & ex) {
    RCLCPP_ERROR(get_logger(), "Error while reopening port: %s", ex.what());
    if (rclcpp::ok()) {
      rclcpp::sleep_for(std::chrono::seconds(1));
      reopenPort();
    }
  }
}

void RMSerialDriver::setParam(const rclcpp::Parameter & param)
{
  const int desired = param.as_int();

  // Quick exit if all nodes are already synced to this value
  bool all_synced = !detector_param_clients_.empty();
  for (const auto & name : detector_node_names_) {
    auto it = last_set_color_.find(name);
    if (it == last_set_color_.end() || it->second != desired) {
      all_synced = false;
      break;
    }
  }
  if (all_synced) {
    return;
  }

  for (const auto & name : detector_node_names_) {
    auto client_it = detector_param_clients_.find(name);
    if (client_it == detector_param_clients_.end()) {
      continue;
    }
    auto & client = client_it->second;

    // Skip if already up-to-date
    if (last_set_color_[name] == desired) {
      continue;
    }

    if (!client->service_is_ready()) {
      // RCLCPP_WARN_THROTTLE(get_logger(), *get_clock(), 2000,
      //                      "Service %s parameter server not ready, will retry...", name.c_str());
      continue;
    }

    auto & future = set_param_futures_[name];
    if (!future.valid() || future.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
      RCLCPP_INFO(get_logger(), "Setting %s.detect_color to %d...", name.c_str(), desired);
      future = client->set_parameters(
        {param}, [this, name, desired](const ResultFuturePtr & results) {
          for (const auto & result : results.get()) {
            if (!result.successful) {
              RCLCPP_ERROR(get_logger(), "Failed to set %s.detect_color: %s", name.c_str(), result.reason.c_str());
              return;
            }
          }
          last_set_color_[name] = desired;
          RCLCPP_INFO(get_logger(), "Successfully set %s.detect_color to %d!", name.c_str(), desired);
        });
    }
  }
}

void RMSerialDriver::resetTracker()
{
  if (!reset_tracker_client_->service_is_ready()) {
    // RCLCPP_WARN(get_logger(), "Service not ready, skipping tracker reset");
    return;
  }

  auto request = std::make_shared<std_srvs::srv::Trigger::Request>();
  reset_tracker_client_->async_send_request(request);
  RCLCPP_INFO(get_logger(), "Reset tracker!");
}

}  // namespace rm_serial_driver

#include "rclcpp_components/register_node_macro.hpp"

// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
RCLCPP_COMPONENTS_REGISTER_NODE(rm_serial_driver::RMSerialDriver)
