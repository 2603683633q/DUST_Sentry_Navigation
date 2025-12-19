// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vision_msg:msg/GimblePosition.idl
// generated code does not contain a copyright notice

#ifndef VISION_MSG__MSG__DETAIL__GIMBLE_POSITION__TRAITS_HPP_
#define VISION_MSG__MSG__DETAIL__GIMBLE_POSITION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vision_msg/msg/detail/gimble_position__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'time_stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace vision_msg
{

namespace msg
{

inline void to_flow_style_yaml(
  const GimblePosition & msg,
  std::ostream & out)
{
  out << "{";
  // member: time_stamp
  {
    out << "time_stamp: ";
    to_flow_style_yaml(msg.time_stamp, out);
    out << ", ";
  }

  // member: yaw
  {
    out << "yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw, out);
    out << ", ";
  }

  // member: pitch
  {
    out << "pitch: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch, out);
    out << ", ";
  }

  // member: armor_id
  {
    out << "armor_id: ";
    rosidl_generator_traits::value_to_yaml(msg.armor_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GimblePosition & msg,
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

  // member: yaw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw, out);
    out << "\n";
  }

  // member: pitch
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pitch: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch, out);
    out << "\n";
  }

  // member: armor_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "armor_id: ";
    rosidl_generator_traits::value_to_yaml(msg.armor_id, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GimblePosition & msg, bool use_flow_style = false)
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
  const vision_msg::msg::GimblePosition & msg,
  std::ostream & out, size_t indentation = 0)
{
  vision_msg::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vision_msg::msg::to_yaml() instead")]]
inline std::string to_yaml(const vision_msg::msg::GimblePosition & msg)
{
  return vision_msg::msg::to_yaml(msg);
}

template<>
inline const char * data_type<vision_msg::msg::GimblePosition>()
{
  return "vision_msg::msg::GimblePosition";
}

template<>
inline const char * name<vision_msg::msg::GimblePosition>()
{
  return "vision_msg/msg/GimblePosition";
}

template<>
struct has_fixed_size<vision_msg::msg::GimblePosition>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<vision_msg::msg::GimblePosition>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<vision_msg::msg::GimblePosition>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VISION_MSG__MSG__DETAIL__GIMBLE_POSITION__TRAITS_HPP_
