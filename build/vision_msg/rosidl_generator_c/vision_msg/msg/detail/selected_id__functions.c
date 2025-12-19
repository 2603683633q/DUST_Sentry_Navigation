// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from vision_msg:msg/SelectedId.idl
// generated code does not contain a copyright notice
#include "vision_msg/msg/detail/selected_id__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `time_stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
vision_msg__msg__SelectedId__init(vision_msg__msg__SelectedId * msg)
{
  if (!msg) {
    return false;
  }
  // time_stamp
  if (!builtin_interfaces__msg__Time__init(&msg->time_stamp)) {
    vision_msg__msg__SelectedId__fini(msg);
    return false;
  }
  // target_id
  return true;
}

void
vision_msg__msg__SelectedId__fini(vision_msg__msg__SelectedId * msg)
{
  if (!msg) {
    return;
  }
  // time_stamp
  builtin_interfaces__msg__Time__fini(&msg->time_stamp);
  // target_id
}

bool
vision_msg__msg__SelectedId__are_equal(const vision_msg__msg__SelectedId * lhs, const vision_msg__msg__SelectedId * rhs)
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
  // target_id
  if (lhs->target_id != rhs->target_id) {
    return false;
  }
  return true;
}

bool
vision_msg__msg__SelectedId__copy(
  const vision_msg__msg__SelectedId * input,
  vision_msg__msg__SelectedId * output)
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
  // target_id
  output->target_id = input->target_id;
  return true;
}

vision_msg__msg__SelectedId *
vision_msg__msg__SelectedId__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vision_msg__msg__SelectedId * msg = (vision_msg__msg__SelectedId *)allocator.allocate(sizeof(vision_msg__msg__SelectedId), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vision_msg__msg__SelectedId));
  bool success = vision_msg__msg__SelectedId__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vision_msg__msg__SelectedId__destroy(vision_msg__msg__SelectedId * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vision_msg__msg__SelectedId__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vision_msg__msg__SelectedId__Sequence__init(vision_msg__msg__SelectedId__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vision_msg__msg__SelectedId * data = NULL;

  if (size) {
    data = (vision_msg__msg__SelectedId *)allocator.zero_allocate(size, sizeof(vision_msg__msg__SelectedId), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vision_msg__msg__SelectedId__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vision_msg__msg__SelectedId__fini(&data[i - 1]);
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
vision_msg__msg__SelectedId__Sequence__fini(vision_msg__msg__SelectedId__Sequence * array)
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
      vision_msg__msg__SelectedId__fini(&array->data[i]);
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

vision_msg__msg__SelectedId__Sequence *
vision_msg__msg__SelectedId__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vision_msg__msg__SelectedId__Sequence * array = (vision_msg__msg__SelectedId__Sequence *)allocator.allocate(sizeof(vision_msg__msg__SelectedId__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vision_msg__msg__SelectedId__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vision_msg__msg__SelectedId__Sequence__destroy(vision_msg__msg__SelectedId__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vision_msg__msg__SelectedId__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vision_msg__msg__SelectedId__Sequence__are_equal(const vision_msg__msg__SelectedId__Sequence * lhs, const vision_msg__msg__SelectedId__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vision_msg__msg__SelectedId__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vision_msg__msg__SelectedId__Sequence__copy(
  const vision_msg__msg__SelectedId__Sequence * input,
  vision_msg__msg__SelectedId__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vision_msg__msg__SelectedId);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vision_msg__msg__SelectedId * data =
      (vision_msg__msg__SelectedId *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vision_msg__msg__SelectedId__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vision_msg__msg__SelectedId__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vision_msg__msg__SelectedId__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
