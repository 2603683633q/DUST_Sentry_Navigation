// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vision_msg:msg/DetectedId.idl
// generated code does not contain a copyright notice

#ifndef VISION_MSG__MSG__DETAIL__DETECTED_ID__BUILDER_HPP_
#define VISION_MSG__MSG__DETAIL__DETECTED_ID__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vision_msg/msg/detail/detected_id__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vision_msg
{

namespace msg
{

namespace builder
{

class Init_DetectedId_distance
{
public:
  explicit Init_DetectedId_distance(::vision_msg::msg::DetectedId & msg)
  : msg_(msg)
  {}
  ::vision_msg::msg::DetectedId distance(::vision_msg::msg::DetectedId::_distance_type arg)
  {
    msg_.distance = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vision_msg::msg::DetectedId msg_;
};

class Init_DetectedId_id
{
public:
  explicit Init_DetectedId_id(::vision_msg::msg::DetectedId & msg)
  : msg_(msg)
  {}
  Init_DetectedId_distance id(::vision_msg::msg::DetectedId::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_DetectedId_distance(msg_);
  }

private:
  ::vision_msg::msg::DetectedId msg_;
};

class Init_DetectedId_time_stamp
{
public:
  Init_DetectedId_time_stamp()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DetectedId_id time_stamp(::vision_msg::msg::DetectedId::_time_stamp_type arg)
  {
    msg_.time_stamp = std::move(arg);
    return Init_DetectedId_id(msg_);
  }

private:
  ::vision_msg::msg::DetectedId msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vision_msg::msg::DetectedId>()
{
  return vision_msg::msg::builder::Init_DetectedId_time_stamp();
}

}  // namespace vision_msg

#endif  // VISION_MSG__MSG__DETAIL__DETECTED_ID__BUILDER_HPP_
