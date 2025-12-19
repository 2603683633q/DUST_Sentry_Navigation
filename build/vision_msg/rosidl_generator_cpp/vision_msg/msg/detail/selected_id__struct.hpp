// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from vision_msg:msg/SelectedId.idl
// generated code does not contain a copyright notice

#ifndef VISION_MSG__MSG__DETAIL__SELECTED_ID__STRUCT_HPP_
#define VISION_MSG__MSG__DETAIL__SELECTED_ID__STRUCT_HPP_

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
# define DEPRECATED__vision_msg__msg__SelectedId __attribute__((deprecated))
#else
# define DEPRECATED__vision_msg__msg__SelectedId __declspec(deprecated)
#endif

namespace vision_msg
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SelectedId_
{
  using Type = SelectedId_<ContainerAllocator>;

  explicit SelectedId_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : time_stamp(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->target_id = 0l;
    }
  }

  explicit SelectedId_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : time_stamp(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->target_id = 0l;
    }
  }

  // field types and members
  using _time_stamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _time_stamp_type time_stamp;
  using _target_id_type =
    int32_t;
  _target_id_type target_id;

  // setters for named parameter idiom
  Type & set__time_stamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->time_stamp = _arg;
    return *this;
  }
  Type & set__target_id(
    const int32_t & _arg)
  {
    this->target_id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    vision_msg::msg::SelectedId_<ContainerAllocator> *;
  using ConstRawPtr =
    const vision_msg::msg::SelectedId_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vision_msg::msg::SelectedId_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vision_msg::msg::SelectedId_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vision_msg::msg::SelectedId_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vision_msg::msg::SelectedId_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vision_msg::msg::SelectedId_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vision_msg::msg::SelectedId_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vision_msg::msg::SelectedId_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vision_msg::msg::SelectedId_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vision_msg__msg__SelectedId
    std::shared_ptr<vision_msg::msg::SelectedId_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vision_msg__msg__SelectedId
    std::shared_ptr<vision_msg::msg::SelectedId_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SelectedId_ & other) const
  {
    if (this->time_stamp != other.time_stamp) {
      return false;
    }
    if (this->target_id != other.target_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const SelectedId_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SelectedId_

// alias to use template instance with default allocator
using SelectedId =
  vision_msg::msg::SelectedId_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace vision_msg

#endif  // VISION_MSG__MSG__DETAIL__SELECTED_ID__STRUCT_HPP_
