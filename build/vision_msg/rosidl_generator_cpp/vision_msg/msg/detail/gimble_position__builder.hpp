// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vision_msg:msg/GimblePosition.idl
// generated code does not contain a copyright notice

#ifndef VISION_MSG__MSG__DETAIL__GIMBLE_POSITION__BUILDER_HPP_
#define VISION_MSG__MSG__DETAIL__GIMBLE_POSITION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vision_msg/msg/detail/gimble_position__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vision_msg
{

namespace msg
{

namespace builder
{

class Init_GimblePosition_armor_id
{
public:
  explicit Init_GimblePosition_armor_id(::vision_msg::msg::GimblePosition & msg)
  : msg_(msg)
  {}
  ::vision_msg::msg::GimblePosition armor_id(::vision_msg::msg::GimblePosition::_armor_id_type arg)
  {
    msg_.armor_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vision_msg::msg::GimblePosition msg_;
};

class Init_GimblePosition_pitch
{
public:
  explicit Init_GimblePosition_pitch(::vision_msg::msg::GimblePosition & msg)
  : msg_(msg)
  {}
  Init_GimblePosition_armor_id pitch(::vision_msg::msg::GimblePosition::_pitch_type arg)
  {
    msg_.pitch = std::move(arg);
    return Init_GimblePosition_armor_id(msg_);
  }

private:
  ::vision_msg::msg::GimblePosition msg_;
};

class Init_GimblePosition_yaw
{
public:
  explicit Init_GimblePosition_yaw(::vision_msg::msg::GimblePosition & msg)
  : msg_(msg)
  {}
  Init_GimblePosition_pitch yaw(::vision_msg::msg::GimblePosition::_yaw_type arg)
  {
    msg_.yaw = std::move(arg);
    return Init_GimblePosition_pitch(msg_);
  }

private:
  ::vision_msg::msg::GimblePosition msg_;
};

class Init_GimblePosition_time_stamp
{
public:
  Init_GimblePosition_time_stamp()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GimblePosition_yaw time_stamp(::vision_msg::msg::GimblePosition::_time_stamp_type arg)
  {
    msg_.time_stamp = std::move(arg);
    return Init_GimblePosition_yaw(msg_);
  }

private:
  ::vision_msg::msg::GimblePosition msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vision_msg::msg::GimblePosition>()
{
  return vision_msg::msg::builder::Init_GimblePosition_time_stamp();
}

}  // namespace vision_msg

#endif  // VISION_MSG__MSG__DETAIL__GIMBLE_POSITION__BUILDER_HPP_
