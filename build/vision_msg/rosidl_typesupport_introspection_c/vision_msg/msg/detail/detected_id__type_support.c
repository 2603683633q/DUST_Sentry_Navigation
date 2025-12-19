// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from vision_msg:msg/DetectedId.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "vision_msg/msg/detail/detected_id__rosidl_typesupport_introspection_c.h"
#include "vision_msg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "vision_msg/msg/detail/detected_id__functions.h"
#include "vision_msg/msg/detail/detected_id__struct.h"


// Include directives for member types
// Member `time_stamp`
#include "builtin_interfaces/msg/time.h"
// Member `time_stamp`
#include "builtin_interfaces/msg/detail/time__rosidl_typesupport_introspection_c.h"
// Member `id`
// Member `distance`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void vision_msg__msg__DetectedId__rosidl_typesupport_introspection_c__DetectedId_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  vision_msg__msg__DetectedId__init(message_memory);
}

void vision_msg__msg__DetectedId__rosidl_typesupport_introspection_c__DetectedId_fini_function(void * message_memory)
{
  vision_msg__msg__DetectedId__fini(message_memory);
}

size_t vision_msg__msg__DetectedId__rosidl_typesupport_introspection_c__size_function__DetectedId__id(
  const void * untyped_member)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return member->size;
}

const void * vision_msg__msg__DetectedId__rosidl_typesupport_introspection_c__get_const_function__DetectedId__id(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void * vision_msg__msg__DetectedId__rosidl_typesupport_introspection_c__get_function__DetectedId__id(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void vision_msg__msg__DetectedId__rosidl_typesupport_introspection_c__fetch_function__DetectedId__id(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int32_t * item =
    ((const int32_t *)
    vision_msg__msg__DetectedId__rosidl_typesupport_introspection_c__get_const_function__DetectedId__id(untyped_member, index));
  int32_t * value =
    (int32_t *)(untyped_value);
  *value = *item;
}

void vision_msg__msg__DetectedId__rosidl_typesupport_introspection_c__assign_function__DetectedId__id(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int32_t * item =
    ((int32_t *)
    vision_msg__msg__DetectedId__rosidl_typesupport_introspection_c__get_function__DetectedId__id(untyped_member, index));
  const int32_t * value =
    (const int32_t *)(untyped_value);
  *item = *value;
}

bool vision_msg__msg__DetectedId__rosidl_typesupport_introspection_c__resize_function__DetectedId__id(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  rosidl_runtime_c__int32__Sequence__fini(member);
  return rosidl_runtime_c__int32__Sequence__init(member, size);
}

size_t vision_msg__msg__DetectedId__rosidl_typesupport_introspection_c__size_function__DetectedId__distance(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * vision_msg__msg__DetectedId__rosidl_typesupport_introspection_c__get_const_function__DetectedId__distance(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * vision_msg__msg__DetectedId__rosidl_typesupport_introspection_c__get_function__DetectedId__distance(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void vision_msg__msg__DetectedId__rosidl_typesupport_introspection_c__fetch_function__DetectedId__distance(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    vision_msg__msg__DetectedId__rosidl_typesupport_introspection_c__get_const_function__DetectedId__distance(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void vision_msg__msg__DetectedId__rosidl_typesupport_introspection_c__assign_function__DetectedId__distance(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    vision_msg__msg__DetectedId__rosidl_typesupport_introspection_c__get_function__DetectedId__distance(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool vision_msg__msg__DetectedId__rosidl_typesupport_introspection_c__resize_function__DetectedId__distance(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember vision_msg__msg__DetectedId__rosidl_typesupport_introspection_c__DetectedId_message_member_array[3] = {
  {
    "time_stamp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vision_msg__msg__DetectedId, time_stamp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vision_msg__msg__DetectedId, id),  // bytes offset in struct
    NULL,  // default value
    vision_msg__msg__DetectedId__rosidl_typesupport_introspection_c__size_function__DetectedId__id,  // size() function pointer
    vision_msg__msg__DetectedId__rosidl_typesupport_introspection_c__get_const_function__DetectedId__id,  // get_const(index) function pointer
    vision_msg__msg__DetectedId__rosidl_typesupport_introspection_c__get_function__DetectedId__id,  // get(index) function pointer
    vision_msg__msg__DetectedId__rosidl_typesupport_introspection_c__fetch_function__DetectedId__id,  // fetch(index, &value) function pointer
    vision_msg__msg__DetectedId__rosidl_typesupport_introspection_c__assign_function__DetectedId__id,  // assign(index, value) function pointer
    vision_msg__msg__DetectedId__rosidl_typesupport_introspection_c__resize_function__DetectedId__id  // resize(index) function pointer
  },
  {
    "distance",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vision_msg__msg__DetectedId, distance),  // bytes offset in struct
    NULL,  // default value
    vision_msg__msg__DetectedId__rosidl_typesupport_introspection_c__size_function__DetectedId__distance,  // size() function pointer
    vision_msg__msg__DetectedId__rosidl_typesupport_introspection_c__get_const_function__DetectedId__distance,  // get_const(index) function pointer
    vision_msg__msg__DetectedId__rosidl_typesupport_introspection_c__get_function__DetectedId__distance,  // get(index) function pointer
    vision_msg__msg__DetectedId__rosidl_typesupport_introspection_c__fetch_function__DetectedId__distance,  // fetch(index, &value) function pointer
    vision_msg__msg__DetectedId__rosidl_typesupport_introspection_c__assign_function__DetectedId__distance,  // assign(index, value) function pointer
    vision_msg__msg__DetectedId__rosidl_typesupport_introspection_c__resize_function__DetectedId__distance  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers vision_msg__msg__DetectedId__rosidl_typesupport_introspection_c__DetectedId_message_members = {
  "vision_msg__msg",  // message namespace
  "DetectedId",  // message name
  3,  // number of fields
  sizeof(vision_msg__msg__DetectedId),
  vision_msg__msg__DetectedId__rosidl_typesupport_introspection_c__DetectedId_message_member_array,  // message members
  vision_msg__msg__DetectedId__rosidl_typesupport_introspection_c__DetectedId_init_function,  // function to initialize message memory (memory has to be allocated)
  vision_msg__msg__DetectedId__rosidl_typesupport_introspection_c__DetectedId_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t vision_msg__msg__DetectedId__rosidl_typesupport_introspection_c__DetectedId_message_type_support_handle = {
  0,
  &vision_msg__msg__DetectedId__rosidl_typesupport_introspection_c__DetectedId_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_vision_msg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vision_msg, msg, DetectedId)() {
  vision_msg__msg__DetectedId__rosidl_typesupport_introspection_c__DetectedId_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Time)();
  if (!vision_msg__msg__DetectedId__rosidl_typesupport_introspection_c__DetectedId_message_type_support_handle.typesupport_identifier) {
    vision_msg__msg__DetectedId__rosidl_typesupport_introspection_c__DetectedId_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &vision_msg__msg__DetectedId__rosidl_typesupport_introspection_c__DetectedId_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
