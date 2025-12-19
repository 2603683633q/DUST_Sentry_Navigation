// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from vision_msg:msg/GimblePosition.idl
// generated code does not contain a copyright notice

#ifndef VISION_MSG__MSG__DETAIL__GIMBLE_POSITION__FUNCTIONS_H_
#define VISION_MSG__MSG__DETAIL__GIMBLE_POSITION__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "vision_msg/msg/rosidl_generator_c__visibility_control.h"

#include "vision_msg/msg/detail/gimble_position__struct.h"

/// Initialize msg/GimblePosition message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * vision_msg__msg__GimblePosition
 * )) before or use
 * vision_msg__msg__GimblePosition__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_vision_msg
bool
vision_msg__msg__GimblePosition__init(vision_msg__msg__GimblePosition * msg);

/// Finalize msg/GimblePosition message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vision_msg
void
vision_msg__msg__GimblePosition__fini(vision_msg__msg__GimblePosition * msg);

/// Create msg/GimblePosition message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * vision_msg__msg__GimblePosition__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_vision_msg
vision_msg__msg__GimblePosition *
vision_msg__msg__GimblePosition__create();

/// Destroy msg/GimblePosition message.
/**
 * It calls
 * vision_msg__msg__GimblePosition__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vision_msg
void
vision_msg__msg__GimblePosition__destroy(vision_msg__msg__GimblePosition * msg);

/// Check for msg/GimblePosition message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_vision_msg
bool
vision_msg__msg__GimblePosition__are_equal(const vision_msg__msg__GimblePosition * lhs, const vision_msg__msg__GimblePosition * rhs);

/// Copy a msg/GimblePosition message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_vision_msg
bool
vision_msg__msg__GimblePosition__copy(
  const vision_msg__msg__GimblePosition * input,
  vision_msg__msg__GimblePosition * output);

/// Initialize array of msg/GimblePosition messages.
/**
 * It allocates the memory for the number of elements and calls
 * vision_msg__msg__GimblePosition__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_vision_msg
bool
vision_msg__msg__GimblePosition__Sequence__init(vision_msg__msg__GimblePosition__Sequence * array, size_t size);

/// Finalize array of msg/GimblePosition messages.
/**
 * It calls
 * vision_msg__msg__GimblePosition__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vision_msg
void
vision_msg__msg__GimblePosition__Sequence__fini(vision_msg__msg__GimblePosition__Sequence * array);

/// Create array of msg/GimblePosition messages.
/**
 * It allocates the memory for the array and calls
 * vision_msg__msg__GimblePosition__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_vision_msg
vision_msg__msg__GimblePosition__Sequence *
vision_msg__msg__GimblePosition__Sequence__create(size_t size);

/// Destroy array of msg/GimblePosition messages.
/**
 * It calls
 * vision_msg__msg__GimblePosition__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vision_msg
void
vision_msg__msg__GimblePosition__Sequence__destroy(vision_msg__msg__GimblePosition__Sequence * array);

/// Check for msg/GimblePosition message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_vision_msg
bool
vision_msg__msg__GimblePosition__Sequence__are_equal(const vision_msg__msg__GimblePosition__Sequence * lhs, const vision_msg__msg__GimblePosition__Sequence * rhs);

/// Copy an array of msg/GimblePosition messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_vision_msg
bool
vision_msg__msg__GimblePosition__Sequence__copy(
  const vision_msg__msg__GimblePosition__Sequence * input,
  vision_msg__msg__GimblePosition__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // VISION_MSG__MSG__DETAIL__GIMBLE_POSITION__FUNCTIONS_H_
