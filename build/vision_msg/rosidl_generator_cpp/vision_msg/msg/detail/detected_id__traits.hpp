// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vision_msg:msg/DetectedId.idl
// generated code does not contain a copyright notice

#ifndef VISION_MSG__MSG__DETAIL__DETECTED_ID__TRAITS_HPP_
#define VISION_MSG__MSG__DETAIL__DETECTED_ID__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vision_msg/msg/detail/detected_id__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'time_stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace vision_msg
{

namespace msg
{

inline void to_flow_style_yaml(
  const DetectedId & msg,
  std::ostream & out)
{
  out << "{";
  // member: time_stamp
  {
    out << "time_stamp: ";
    to_flow_style_yaml(msg.time_stamp, out);
    out << ", ";
  }

  // member: id
  {
    if (msg.id.size() == 0) {
      out << "id: []";
    } else {
      out << "id: [";
      size_t pending_items = msg.id.size();
      for (auto item : msg.id) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: distance
  {
    if (msg.distance.size() == 0) {
      out << "distance: []";
    } else {
      out << "distance: [";
      size_t pending_items = msg.distance.size();
      for (auto item : msg.distance) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DetectedId & msg,
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

  // member: id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.id.size() == 0) {
      out << "id: []\n";
    } else {
      out << "id:\n";
      for (auto item : msg.id) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: distance
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.distance.size() == 0) {
      out << "distance: []\n";
    } else {
      out << "distance:\n";
      for (auto item : msg.distance) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DetectedId & msg, bool use_flow_style = false)
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
  const vision_msg::msg::DetectedId & msg,
  std::ostream & out, size_t indentation = 0)
{
  vision_msg::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vision_msg::msg::to_yaml() instead")]]
inline std::string to_yaml(const vision_msg::msg::DetectedId & msg)
{
  return vision_msg::msg::to_yaml(msg);
}

template<>
inline const char * data_type<vision_msg::msg::DetectedId>()
{
  return "vision_msg::msg::DetectedId";
}

template<>
inline const char * name<vision_msg::msg::DetectedId>()
{
  return "vision_msg/msg/DetectedId";
}

template<>
struct has_fixed_size<vision_msg::msg::DetectedId>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<vision_msg::msg::DetectedId>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<vision_msg::msg::DetectedId>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VISION_MSG__MSG__DETAIL__DETECTED_ID__TRAITS_HPP_
