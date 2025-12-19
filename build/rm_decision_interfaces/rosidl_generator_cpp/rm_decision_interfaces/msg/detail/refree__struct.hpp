// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rm_decision_interfaces:msg/Refree.idl
// generated code does not contain a copyright notice

#ifndef RM_DECISION_INTERFACES__MSG__DETAIL__REFREE__STRUCT_HPP_
#define RM_DECISION_INTERFACES__MSG__DETAIL__REFREE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__rm_decision_interfaces__msg__Refree __attribute__((deprecated))
#else
# define DEPRECATED__rm_decision_interfaces__msg__Refree __declspec(deprecated)
#endif

namespace rm_decision_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Refree_
{
  using Type = Refree_<ContainerAllocator>;

  explicit Refree_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->robot_hp = 0;
    }
  }

  explicit Refree_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->robot_hp = 0;
    }
  }

  // field types and members
  using _robot_hp_type =
    uint16_t;
  _robot_hp_type robot_hp;

  // setters for named parameter idiom
  Type & set__robot_hp(
    const uint16_t & _arg)
  {
    this->robot_hp = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rm_decision_interfaces::msg::Refree_<ContainerAllocator> *;
  using ConstRawPtr =
    const rm_decision_interfaces::msg::Refree_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rm_decision_interfaces::msg::Refree_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rm_decision_interfaces::msg::Refree_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rm_decision_interfaces::msg::Refree_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rm_decision_interfaces::msg::Refree_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rm_decision_interfaces::msg::Refree_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rm_decision_interfaces::msg::Refree_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rm_decision_interfaces::msg::Refree_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rm_decision_interfaces::msg::Refree_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rm_decision_interfaces__msg__Refree
    std::shared_ptr<rm_decision_interfaces::msg::Refree_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rm_decision_interfaces__msg__Refree
    std::shared_ptr<rm_decision_interfaces::msg::Refree_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Refree_ & other) const
  {
    if (this->robot_hp != other.robot_hp) {
      return false;
    }
    return true;
  }
  bool operator!=(const Refree_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Refree_

// alias to use template instance with default allocator
using Refree =
  rm_decision_interfaces::msg::Refree_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rm_decision_interfaces

#endif  // RM_DECISION_INTERFACES__MSG__DETAIL__REFREE__STRUCT_HPP_
