// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vision_msg:msg/SelectedId.idl
// generated code does not contain a copyright notice

#ifndef VISION_MSG__MSG__DETAIL__SELECTED_ID__BUILDER_HPP_
#define VISION_MSG__MSG__DETAIL__SELECTED_ID__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vision_msg/msg/detail/selected_id__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vision_msg
{

namespace msg
{

namespace builder
{

class Init_SelectedId_target_id
{
public:
  explicit Init_SelectedId_target_id(::vision_msg::msg::SelectedId & msg)
  : msg_(msg)
  {}
  ::vision_msg::msg::SelectedId target_id(::vision_msg::msg::SelectedId::_target_id_type arg)
  {
    msg_.target_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vision_msg::msg::SelectedId msg_;
};

class Init_SelectedId_time_stamp
{
public:
  Init_SelectedId_time_stamp()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SelectedId_target_id time_stamp(::vision_msg::msg::SelectedId::_time_stamp_type arg)
  {
    msg_.time_stamp = std::move(arg);
    return Init_SelectedId_target_id(msg_);
  }

private:
  ::vision_msg::msg::SelectedId msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vision_msg::msg::SelectedId>()
{
  return vision_msg::msg::builder::Init_SelectedId_time_stamp();
}

}  // namespace vision_msg

#endif  // VISION_MSG__MSG__DETAIL__SELECTED_ID__BUILDER_HPP_
