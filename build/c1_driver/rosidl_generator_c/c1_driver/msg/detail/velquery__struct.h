// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from c1_driver:msg/Velquery.idl
// generated code does not contain a copyright notice

#ifndef C1_DRIVER__MSG__DETAIL__VELQUERY__STRUCT_H_
#define C1_DRIVER__MSG__DETAIL__VELQUERY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Velquery in the package c1_driver.
typedef struct c1_driver__msg__Velquery
{
  int32_t id;
  int16_t byte0;
  int16_t byte1;
  int16_t byte2;
  int16_t byte3;
  int16_t byte4;
  int16_t byte5;
  int16_t byte6;
  int16_t byte7;
} c1_driver__msg__Velquery;

// Struct for a sequence of c1_driver__msg__Velquery.
typedef struct c1_driver__msg__Velquery__Sequence
{
  c1_driver__msg__Velquery * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} c1_driver__msg__Velquery__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // C1_DRIVER__MSG__DETAIL__VELQUERY__STRUCT_H_
