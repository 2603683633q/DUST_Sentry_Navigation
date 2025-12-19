// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vision_msg:msg/SelectedId.idl
// generated code does not contain a copyright notice

#ifndef VISION_MSG__MSG__DETAIL__SELECTED_ID__STRUCT_H_
#define VISION_MSG__MSG__DETAIL__SELECTED_ID__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'time_stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in msg/SelectedId in the package vision_msg.
typedef struct vision_msg__msg__SelectedId
{
  /// 时间戳
  builtin_interfaces__msg__Time time_stamp;
  int32_t target_id;
} vision_msg__msg__SelectedId;

// Struct for a sequence of vision_msg__msg__SelectedId.
typedef struct vision_msg__msg__SelectedId__Sequence
{
  vision_msg__msg__SelectedId * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vision_msg__msg__SelectedId__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VISION_MSG__MSG__DETAIL__SELECTED_ID__STRUCT_H_
