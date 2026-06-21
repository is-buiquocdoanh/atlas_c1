// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from c1_driver:msg/Velinfo.idl
// generated code does not contain a copyright notice

#ifndef C1_DRIVER__MSG__DETAIL__VELINFO__FUNCTIONS_H_
#define C1_DRIVER__MSG__DETAIL__VELINFO__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "c1_driver/msg/rosidl_generator_c__visibility_control.h"

#include "c1_driver/msg/detail/velinfo__struct.h"

/// Initialize msg/Velinfo message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * c1_driver__msg__Velinfo
 * )) before or use
 * c1_driver__msg__Velinfo__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_c1_driver
bool
c1_driver__msg__Velinfo__init(c1_driver__msg__Velinfo * msg);

/// Finalize msg/Velinfo message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_c1_driver
void
c1_driver__msg__Velinfo__fini(c1_driver__msg__Velinfo * msg);

/// Create msg/Velinfo message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * c1_driver__msg__Velinfo__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_c1_driver
c1_driver__msg__Velinfo *
c1_driver__msg__Velinfo__create();

/// Destroy msg/Velinfo message.
/**
 * It calls
 * c1_driver__msg__Velinfo__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_c1_driver
void
c1_driver__msg__Velinfo__destroy(c1_driver__msg__Velinfo * msg);

/// Check for msg/Velinfo message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_c1_driver
bool
c1_driver__msg__Velinfo__are_equal(const c1_driver__msg__Velinfo * lhs, const c1_driver__msg__Velinfo * rhs);

/// Copy a msg/Velinfo message.
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
ROSIDL_GENERATOR_C_PUBLIC_c1_driver
bool
c1_driver__msg__Velinfo__copy(
  const c1_driver__msg__Velinfo * input,
  c1_driver__msg__Velinfo * output);

/// Initialize array of msg/Velinfo messages.
/**
 * It allocates the memory for the number of elements and calls
 * c1_driver__msg__Velinfo__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_c1_driver
bool
c1_driver__msg__Velinfo__Sequence__init(c1_driver__msg__Velinfo__Sequence * array, size_t size);

/// Finalize array of msg/Velinfo messages.
/**
 * It calls
 * c1_driver__msg__Velinfo__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_c1_driver
void
c1_driver__msg__Velinfo__Sequence__fini(c1_driver__msg__Velinfo__Sequence * array);

/// Create array of msg/Velinfo messages.
/**
 * It allocates the memory for the array and calls
 * c1_driver__msg__Velinfo__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_c1_driver
c1_driver__msg__Velinfo__Sequence *
c1_driver__msg__Velinfo__Sequence__create(size_t size);

/// Destroy array of msg/Velinfo messages.
/**
 * It calls
 * c1_driver__msg__Velinfo__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_c1_driver
void
c1_driver__msg__Velinfo__Sequence__destroy(c1_driver__msg__Velinfo__Sequence * array);

/// Check for msg/Velinfo message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_c1_driver
bool
c1_driver__msg__Velinfo__Sequence__are_equal(const c1_driver__msg__Velinfo__Sequence * lhs, const c1_driver__msg__Velinfo__Sequence * rhs);

/// Copy an array of msg/Velinfo messages.
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
ROSIDL_GENERATOR_C_PUBLIC_c1_driver
bool
c1_driver__msg__Velinfo__Sequence__copy(
  const c1_driver__msg__Velinfo__Sequence * input,
  c1_driver__msg__Velinfo__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // C1_DRIVER__MSG__DETAIL__VELINFO__FUNCTIONS_H_
