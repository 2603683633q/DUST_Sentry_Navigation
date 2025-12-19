// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from vision_msg:msg/DetectedId.idl
// generated code does not contain a copyright notice

#ifndef VISION_MSG__MSG__DETAIL__DETECTED_ID__STRUCT_HPP_
#define VISION_MSG__MSG__DETAIL__DETECTED_ID__STRUCT_HPP_

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
# define DEPRECATED__vision_msg__msg__DetectedId __attribute__((deprecated))
#else
# define DEPRECATED__vision_msg__msg__DetectedId __declspec(deprecated)
#endif

namespace vision_msg
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct DetectedId_
{
  using Type = DetectedId_<ContainerAllocator>;

  explicit DetectedId_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : time_stamp(_init)
  {
    (void)_init;
  }

  explicit DetectedId_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : time_stamp(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _time_stamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _time_stamp_type time_stamp;
  using _id_type =
    std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>>;
  _id_type id;
  using _distance_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _distance_type distance;

  // setters for named parameter idiom
  Type & set__time_stamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->time_stamp = _arg;
    return *this;
  }
  Type & set__id(
    const std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>> & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__distance(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->distance = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    vision_msg::msg::DetectedId_<ContainerAllocator> *;
  using ConstRawPtr =
    const vision_msg::msg::DetectedId_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vision_msg::msg::DetectedId_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vision_msg::msg::DetectedId_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vision_msg::msg::DetectedId_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vision_msg::msg::DetectedId_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vision_msg::msg::DetectedId_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vision_msg::msg::DetectedId_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vision_msg::msg::DetectedId_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vision_msg::msg::DetectedId_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vision_msg__msg__DetectedId
    std::shared_ptr<vision_msg::msg::DetectedId_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vision_msg__msg__DetectedId
    std::shared_ptr<vision_msg::msg::DetectedId_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DetectedId_ & other) const
  {
    if (this->time_stamp != other.time_stamp) {
      return false;
    }
    if (this->id != other.id) {
      return false;
    }
    if (this->distance != other.distance) {
      return false;
    }
    return true;
  }
  bool operator!=(const DetectedId_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DetectedId_

// alias to use template instance with default allocator
using DetectedId =
  vision_msg::msg::DetectedId_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace vision_msg

#endif  // VISION_MSG__MSG__DETAIL__DETECTED_ID__STRUCT_HPP_
