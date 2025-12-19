// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vision_msg:msg/SelectedId.idl
// generated code does not contain a copyright notice

#ifndef VISION_MSG__MSG__DETAIL__SELECTED_ID__TRAITS_HPP_
#define VISION_MSG__MSG__DETAIL__SELECTED_ID__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vision_msg/msg/detail/selected_id__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'time_stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace vision_msg
{

namespace msg
{

inline void to_flow_style_yaml(
  const SelectedId & msg,
  std::ostream & out)
{
  out << "{";
  // member: time_stamp
  {
    out << "time_stamp: ";
    to_flow_style_yaml(msg.time_stamp, out);
    out << ", ";
  }

  // member: target_id
  {
    out << "target_id: ";
    rosidl_generator_traits::value_to_yaml(msg.target_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SelectedId & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: time_stamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "time_stamp:\n";
    to_block_style_yaml(msg.time_stamp, out, indentation + 2);
  }

  // member: target_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target_id: ";
    rosidl_generator_traits::value_to_yaml(msg.target_id, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SelectedId & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace vision_msg

namespace rosidl_generator_traits
{

[[deprecated("use vision_msg::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const vision_msg::msg::SelectedId & msg,
  std::ostream & out, size_t indentation = 0)
{
  vision_msg::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vision_msg::msg::to_yaml() instead")]]
inline std::string to_yaml(const vision_msg::msg::SelectedId & msg)
{
  return vision_msg::msg::to_yaml(msg);
}

template<>
inline const char * data_type<vision_msg::msg::SelectedId>()
{
  return "vision_msg::msg::SelectedId";
}

template<>
inline const char * name<vision_msg::msg::SelectedId>()
{
  return "vision_msg/msg/SelectedId";
}

template<>
struct has_fixed_size<vision_msg::msg::SelectedId>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<vision_msg::msg::SelectedId>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<vision_msg::msg::SelectedId>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VISION_MSG__MSG__DETAIL__SELECTED_ID__TRAITS_HPP_
