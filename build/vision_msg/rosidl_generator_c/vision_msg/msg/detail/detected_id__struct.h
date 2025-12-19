// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vision_msg:msg/DetectedId.idl
// generated code does not contain a copyright notice

#ifndef VISION_MSG__MSG__DETAIL__DETECTED_ID__STRUCT_H_
#define VISION_MSG__MSG__DETAIL__DETECTED_ID__STRUCT_H_

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
// Member 'id'
// Member 'distance'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/DetectedId in the package vision_msg.
typedef struct vision_msg__msg__DetectedId
{
  /// 时间戳
  builtin_interfaces__msg__Time time_stamp;
  rosidl_runtime_c__int32__Sequence id;
  rosidl_runtime_c__float__Sequence distance;
} vision_msg__msg__DetectedId;

// Struct for a sequence of vision_msg__msg__DetectedId.
typedef struct vision_msg__msg__DetectedId__Sequence
{
  vision_msg__msg__DetectedId * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vision_msg__msg__DetectedId__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VISION_MSG__MSG__DETAIL__DETECTED_ID__STRUCT_H_
