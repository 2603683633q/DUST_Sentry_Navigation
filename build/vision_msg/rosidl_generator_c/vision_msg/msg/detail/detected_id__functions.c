// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from vision_msg:msg/DetectedId.idl
// generated code does not contain a copyright notice
#include "vision_msg/msg/detail/detected_id__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `time_stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"
// Member `id`
// Member `distance`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
vision_msg__msg__DetectedId__init(vision_msg__msg__DetectedId * msg)
{
  if (!msg) {
    return false;
  }
  // time_stamp
  if (!builtin_interfaces__msg__Time__init(&msg->time_stamp)) {
    vision_msg__msg__DetectedId__fini(msg);
    return false;
  }
  // id
  if (!rosidl_runtime_c__int32__Sequence__init(&msg->id, 0)) {
    vision_msg__msg__DetectedId__fini(msg);
    return false;
  }
  // distance
  if (!rosidl_runtime_c__float__Sequence__init(&msg->distance, 0)) {
    vision_msg__msg__DetectedId__fini(msg);
    return false;
  }
  return true;
}

void
vision_msg__msg__DetectedId__fini(vision_msg__msg__DetectedId * msg)
{
  if (!msg) {
    return;
  }
  // time_stamp
  builtin_interfaces__msg__Time__fini(&msg->time_stamp);
  // id
  rosidl_runtime_c__int32__Sequence__fini(&msg->id);
  // distance
  rosidl_runtime_c__float__Sequence__fini(&msg->distance);
}

bool
vision_msg__msg__DetectedId__are_equal(const vision_msg__msg__DetectedId * lhs, const vision_msg__msg__DetectedId * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // time_stamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->time_stamp), &(rhs->time_stamp)))
  {
    return false;
  }
  // id
  if (!rosidl_runtime_c__int32__Sequence__are_equal(
      &(lhs->id), &(rhs->id)))
  {
    return false;
  }
  // distance
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->distance), &(rhs->distance)))
  {
    return false;
  }
  return true;
}

bool
vision_msg__msg__DetectedId__copy(
  const vision_msg__msg__DetectedId * input,
  vision_msg__msg__DetectedId * output)
{
  if (!input || !output) {
    return false;
  }
  // time_stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->time_stamp), &(output->time_stamp)))
  {
    return false;
  }
  // id
  if (!rosidl_runtime_c__int32__Sequence__copy(
      &(input->id), &(output->id)))
  {
    return false;
  }
  // distance
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->distance), &(output->distance)))
  {
    return false;
  }
  return true;
}

vision_msg__msg__DetectedId *
vision_msg__msg__DetectedId__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vision_msg__msg__DetectedId * msg = (vision_msg__msg__DetectedId *)allocator.allocate(sizeof(vision_msg__msg__DetectedId), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vision_msg__msg__DetectedId));
  bool success = vision_msg__msg__DetectedId__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vision_msg__msg__DetectedId__destroy(vision_msg__msg__DetectedId * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vision_msg__msg__DetectedId__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vision_msg__msg__DetectedId__Sequence__init(vision_msg__msg__DetectedId__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vision_msg__msg__DetectedId * data = NULL;

  if (size) {
    data = (vision_msg__msg__DetectedId *)allocator.zero_allocate(size, sizeof(vision_msg__msg__DetectedId), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vision_msg__msg__DetectedId__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vision_msg__msg__DetectedId__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
vision_msg__msg__DetectedId__Sequence__fini(vision_msg__msg__DetectedId__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      vision_msg__msg__DetectedId__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

vision_msg__msg__DetectedId__Sequence *
vision_msg__msg__DetectedId__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vision_msg__msg__DetectedId__Sequence * array = (vision_msg__msg__DetectedId__Sequence *)allocator.allocate(sizeof(vision_msg__msg__DetectedId__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vision_msg__msg__DetectedId__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vision_msg__msg__DetectedId__Sequence__destroy(vision_msg__msg__DetectedId__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vision_msg__msg__DetectedId__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vision_msg__msg__DetectedId__Sequence__are_equal(const vision_msg__msg__DetectedId__Sequence * lhs, const vision_msg__msg__DetectedId__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vision_msg__msg__DetectedId__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vision_msg__msg__DetectedId__Sequence__copy(
  const vision_msg__msg__DetectedId__Sequence * input,
  vision_msg__msg__DetectedId__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vision_msg__msg__DetectedId);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vision_msg__msg__DetectedId * data =
      (vision_msg__msg__DetectedId *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vision_msg__msg__DetectedId__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vision_msg__msg__DetectedId__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vision_msg__msg__DetectedId__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
