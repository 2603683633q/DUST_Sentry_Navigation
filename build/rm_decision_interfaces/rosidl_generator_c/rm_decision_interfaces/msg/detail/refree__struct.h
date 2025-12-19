// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rm_decision_interfaces:msg/Refree.idl
// generated code does not contain a copyright notice

#ifndef RM_DECISION_INTERFACES__MSG__DETAIL__REFREE__STRUCT_H_
#define RM_DECISION_INTERFACES__MSG__DETAIL__REFREE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Refree in the package rm_decision_interfaces.
typedef struct rm_decision_interfaces__msg__Refree
{
  uint16_t robot_hp;
} rm_decision_interfaces__msg__Refree;

// Struct for a sequence of rm_decision_interfaces__msg__Refree.
typedef struct rm_decision_interfaces__msg__Refree__Sequence
{
  rm_decision_interfaces__msg__Refree * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rm_decision_interfaces__msg__Refree__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RM_DECISION_INTERFACES__MSG__DETAIL__REFREE__STRUCT_H_
