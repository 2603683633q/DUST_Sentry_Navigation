// Copyright (c) 2022 ChenJun
// Licensed under the Apache-2.0 License.

#ifndef RM_SERIAL_DRIVER__RM_SERIAL_DRIVER_HPP_
#define RM_SERIAL_DRIVER__RM_SERIAL_DRIVER_HPP_

#include <tf2_ros/transform_broadcaster.h>

#include <auto_aim_interfaces/msg/detail/gimbal_cmd__struct.hpp>
#include <geometry_msgs/msg/transform_stamped.hpp>
#include <rclcpp/publisher.hpp>
#include <rclcpp/rclcpp.hpp>
#include <rclcpp/subscription.hpp>
#include <serial_driver/serial_driver.hpp>
#include <std_msgs/msg/float64.hpp>
#include <std_srvs/srv/trigger.hpp>
#include <visualization_msgs/msg/marker.hpp>
#include "rm_decision_interfaces/msg/refree.hpp"

// C++ system
#include <future>
#include <memory>
#include <string>
#include <thread>
#include <vector>
#include <unordered_map>

#include "auto_aim_interfaces/msg/gimbal_cmd.hpp"

#include <geometry_msgs/msg/twist.hpp>

// 决策依赖库
// #include "decision_moudle/msg/hp.hpp"
// #include "decision_moudle/msg/site.hpp"

namespace rm_serial_driver
{
class RMSerialDriver : public rclcpp::Node
{
public:
  explicit RMSerialDriver(const rclcpp::NodeOptions & options);

  ~RMSerialDriver() override;

private:
  void getParams();

  void receiveData();

  void sendData(auto_aim_interfaces::msg::GimbalCmd::SharedPtr msg);

  void reopenPort();

  void setParam(const rclcpp::Parameter & param);

  void resetTracker();

  // Serial port
  std::unique_ptr<IoContext> owned_ctx_;
  std::string device_name_; 
  std::unique_ptr<drivers::serial_driver::SerialPortConfig> device_config_;
  std::unique_ptr<drivers::serial_driver::SerialDriver> serial_driver_;

  // Param clients to set detect_color on one or more detector nodes
  using ResultFuturePtr = std::shared_future<std::vector<rcl_interfaces::msg::SetParametersResult>>;
  // Desired color last received from serial
  uint8_t previous_receive_color_ = 0;
  // Names of detector nodes to configure
  std::vector<std::string> detector_node_names_;
  // Per-node AsyncParametersClient
  std::unordered_map<std::string, rclcpp::AsyncParametersClient::SharedPtr> detector_param_clients_;
  // Per-node inflight future
  std::unordered_map<std::string, ResultFuturePtr> set_param_futures_;
  // Per-node last applied color (-1 means never set)
  std::unordered_map<std::string, int> last_set_color_;

  // Service client to reset tracker
  rclcpp::Client<std_srvs::srv::Trigger>::SharedPtr reset_tracker_client_;

  // Aimimg point receiving from serial port for visualization
  visualization_msgs::msg::Marker aiming_point_;

  // 决策消息
  // decision_moudle::msg::Site site_msg;
  // decision_moudle::msg::Hp hp_msg;
  // 发布给决策模块的裁判数据
  rclcpp::Publisher<rm_decision_interfaces::msg::Refree>::SharedPtr refree_pub_;

  // Broadcast tf from odom to gimbal_link
  double timestamp_offset_ = 0;
  std::unique_ptr<tf2_ros::TransformBroadcaster> tf_broadcaster_;

  rclcpp::Subscription<auto_aim_interfaces::msg::GimbalCmd>::SharedPtr gimbal_cmd_sub_;
  rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_sub_;

  // For debug usage
  rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr latency_pub_;
  rclcpp::Publisher<visualization_msgs::msg::Marker>::SharedPtr marker_pub_;

  // rclcpp::Publisher<decision_moudle::msg::Site>::SharedPtr site_pub;
  // rclcpp::Publisher<decision_moudle::msg::Hp>::SharedPtr health_pub;

  std::thread receive_thread_;
};
}  // namespace rm_serial_driver

#endif  // RM_SERIAL_DRIVER__RM_SERIAL_DRIVER_HPP_
