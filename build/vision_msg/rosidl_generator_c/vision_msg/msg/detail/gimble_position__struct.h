// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vision_msg:msg/GimblePosition.idl
// generated code does not contain a copyright notice

#ifndef VISION_MSG__MSG__DETAIL__GIMBLE_POSITION__STRUCT_H_
#define VISION_MSG__MSG__DETAIL__GIMBLE_POSITION__STRUCT_H_

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

/// Struct defined in msg/GimblePosition in the package vision_msg.
typedef struct vision_msg__msg__GimblePosition
{
  /// 时间戳
  builtin_interfaces__msg__Time time_stamp;
  /// 右转为正，左转为负（幅度制）
  float yaw;
  /// 上转为正，下转为负（幅度制）
  float pitch;
  /// 目标装甲板id
  int32_t armor_id;
} vision_msg__msg__GimblePosition;

// Struct for a sequence of vision_msg__msg__GimblePosition.
typedef struct vision_msg__msg__GimblePosition__Sequence
{
  vision_msg__msg__GimblePosition * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vision_msg__msg__GimblePosition__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VISION_MSG__MSG__DETAIL__GIMBLE_POSITION__STRUCT_H_
