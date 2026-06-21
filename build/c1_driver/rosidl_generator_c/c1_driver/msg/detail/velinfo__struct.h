// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from c1_driver:msg/Velinfo.idl
// generated code does not contain a copyright notice

#ifndef C1_DRIVER__MSG__DETAIL__VELINFO__STRUCT_H_
#define C1_DRIVER__MSG__DETAIL__VELINFO__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Velinfo in the package c1_driver.
typedef struct c1_driver__msg__Velinfo
{
  uint32_t idsend;
  uint8_t byte0;
  uint8_t byte1;
  uint8_t byte2;
  uint8_t byte3;
  uint8_t byte4;
  uint8_t byte5;
  uint8_t byte6;
  uint8_t byte7;
} c1_driver__msg__Velinfo;

// Struct for a sequence of c1_driver__msg__Velinfo.
typedef struct c1_driver__msg__Velinfo__Sequence
{
  c1_driver__msg__Velinfo * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} c1_driver__msg__Velinfo__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // C1_DRIVER__MSG__DETAIL__VELINFO__STRUCT_H_
