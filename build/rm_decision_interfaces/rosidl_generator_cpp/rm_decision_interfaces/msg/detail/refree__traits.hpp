// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rm_decision_interfaces:msg/Refree.idl
// generated code does not contain a copyright notice

#ifndef RM_DECISION_INTERFACES__MSG__DETAIL__REFREE__TRAITS_HPP_
#define RM_DECISION_INTERFACES__MSG__DETAIL__REFREE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "rm_decision_interfaces/msg/detail/refree__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace rm_decision_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Refree & msg,
  std::ostream & out)
{
  out << "{";
  // member: robot_hp
  {
    out << "robot_hp: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_hp, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Refree & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: robot_hp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "robot_hp: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_hp, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Refree & msg, bool use_flow_style = false)
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

}  // namespace rm_decision_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use rm_decision_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const rm_decision_interfaces::msg::Refree & msg,
  std::ostream & out, size_t indentation = 0)
{
  rm_decision_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rm_decision_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const rm_decision_interfaces::msg::Refree & msg)
{
  return rm_decision_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<rm_decision_interfaces::msg::Refree>()
{
  return "rm_decision_interfaces::msg::Refree";
}

template<>
inline const char * name<rm_decision_interfaces::msg::Refree>()
{
  return "rm_decision_interfaces/msg/Refree";
}

template<>
struct has_fixed_size<rm_decision_interfaces::msg::Refree>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<rm_decision_interfaces::msg::Refree>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<rm_decision_interfaces::msg::Refree>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // RM_DECISION_INTERFACES__MSG__DETAIL__REFREE__TRAITS_HPP_
