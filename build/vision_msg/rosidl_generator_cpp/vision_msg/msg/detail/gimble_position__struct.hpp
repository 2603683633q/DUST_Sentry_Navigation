// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from vision_msg:msg/GimblePosition.idl
// generated code does not contain a copyright notice

#ifndef VISION_MSG__MSG__DETAIL__GIMBLE_POSITION__STRUCT_HPP_
#define VISION_MSG__MSG__DETAIL__GIMBLE_POSITION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'time_stamp'
#include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__vision_msg__msg__GimblePosition __attribute__((deprecated))
#else
# define DEPRECATED__vision_msg__msg__GimblePosition __declspec(deprecated)
#endif

namespace vision_msg
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct GimblePosition_
{
  using Type = GimblePosition_<ContainerAllocator>;

  explicit GimblePosition_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : time_stamp(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::DEFAULTS_ONLY == _init)
    {
      this->armor_id = 0l;
    } else if (rosidl_runtime_cpp::MessageInitialization::ZERO == _init) {
      this->yaw = 0.0f;
      this->pitch = 0.0f;
      this->armor_id = 0l;
    }
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->yaw = 0.0f;
      this->pitch = 0.0f;
    }
  }

  explicit GimblePosition_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : time_stamp(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::DEFAULTS_ONLY == _init)
    {
      this->armor_id = 0l;
    } else if (rosidl_runtime_cpp::MessageInitialization::ZERO == _init) {
      this->yaw = 0.0f;
      this->pitch = 0.0f;
      this->armor_id = 0l;
    }
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->yaw = 0.0f;
      this->pitch = 0.0f;
    }
  }

  // field types and members
  using _time_stamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _time_stamp_type time_stamp;
  using _yaw_type =
    float;
  _yaw_type yaw;
  using _pitch_type =
    float;
  _pitch_type pitch;
  using _armor_id_type =
    int32_t;
  _armor_id_type armor_id;

  // setters for named parameter idiom
  Type & set__time_stamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->time_stamp = _arg;
    return *this;
  }
  Type & set__yaw(
    const float & _arg)
  {
    this->yaw = _arg;
    return *this;
  }
  Type & set__pitch(
    const float & _arg)
  {
    this->pitch = _arg;
    return *this;
  }
  Type & set__armor_id(
    const int32_t & _arg)
  {
    this->armor_id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    vision_msg::msg::GimblePosition_<ContainerAllocator> *;
  using ConstRawPtr =
    const vision_msg::msg::GimblePosition_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vision_msg::msg::GimblePosition_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vision_msg::msg::GimblePosition_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vision_msg::msg::GimblePosition_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vision_msg::msg::GimblePosition_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vision_msg::msg::GimblePosition_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vision_msg::msg::GimblePosition_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vision_msg::msg::GimblePosition_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vision_msg::msg::GimblePosition_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vision_msg__msg__GimblePosition
    std::shared_ptr<vision_msg::msg::GimblePosition_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vision_msg__msg__GimblePosition
    std::shared_ptr<vision_msg::msg::GimblePosition_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GimblePosition_ & other) const
  {
    if (this->time_stamp != other.time_stamp) {
      return false;
    }
    if (this->yaw != other.yaw) {
      return false;
    }
    if (this->pitch != other.pitch) {
      return false;
    }
    if (this->armor_id != other.armor_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const GimblePosition_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GimblePosition_

// alias to use template instance with default allocator
using GimblePosition =
  vision_msg::msg::GimblePosition_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace vision_msg

#endif  // VISION_MSG__MSG__DETAIL__GIMBLE_POSITION__STRUCT_HPP_
