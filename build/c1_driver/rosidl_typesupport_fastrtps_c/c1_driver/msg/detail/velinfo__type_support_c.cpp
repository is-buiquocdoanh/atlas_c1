// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from c1_driver:msg/Velinfo.idl
// generated code does not contain a copyright notice
#include "c1_driver/msg/detail/velinfo__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "c1_driver/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "c1_driver/msg/detail/velinfo__struct.h"
#include "c1_driver/msg/detail/velinfo__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _Velinfo__ros_msg_type = c1_driver__msg__Velinfo;

static bool _Velinfo__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Velinfo__ros_msg_type * ros_message = static_cast<const _Velinfo__ros_msg_type *>(untyped_ros_message);
  // Field name: idsend
  {
    cdr << ros_message->idsend;
  }

  // Field name: byte0
  {
    cdr << ros_message->byte0;
  }

  // Field name: byte1
  {
    cdr << ros_message->byte1;
  }

  // Field name: byte2
  {
    cdr << ros_message->byte2;
  }

  // Field name: byte3
  {
    cdr << ros_message->byte3;
  }

  // Field name: byte4
  {
    cdr << ros_message->byte4;
  }

  // Field name: byte5
  {
    cdr << ros_message->byte5;
  }

  // Field name: byte6
  {
    cdr << ros_message->byte6;
  }

  // Field name: byte7
  {
    cdr << ros_message->byte7;
  }

  return true;
}

static bool _Velinfo__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Velinfo__ros_msg_type * ros_message = static_cast<_Velinfo__ros_msg_type *>(untyped_ros_message);
  // Field name: idsend
  {
    cdr >> ros_message->idsend;
  }

  // Field name: byte0
  {
    cdr >> ros_message->byte0;
  }

  // Field name: byte1
  {
    cdr >> ros_message->byte1;
  }

  // Field name: byte2
  {
    cdr >> ros_message->byte2;
  }

  // Field name: byte3
  {
    cdr >> ros_message->byte3;
  }

  // Field name: byte4
  {
    cdr >> ros_message->byte4;
  }

  // Field name: byte5
  {
    cdr >> ros_message->byte5;
  }

  // Field name: byte6
  {
    cdr >> ros_message->byte6;
  }

  // Field name: byte7
  {
    cdr >> ros_message->byte7;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_c1_driver
size_t get_serialized_size_c1_driver__msg__Velinfo(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Velinfo__ros_msg_type * ros_message = static_cast<const _Velinfo__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name idsend
  {
    size_t item_size = sizeof(ros_message->idsend);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name byte0
  {
    size_t item_size = sizeof(ros_message->byte0);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name byte1
  {
    size_t item_size = sizeof(ros_message->byte1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name byte2
  {
    size_t item_size = sizeof(ros_message->byte2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name byte3
  {
    size_t item_size = sizeof(ros_message->byte3);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name byte4
  {
    size_t item_size = sizeof(ros_message->byte4);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name byte5
  {
    size_t item_size = sizeof(ros_message->byte5);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name byte6
  {
    size_t item_size = sizeof(ros_message->byte6);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name byte7
  {
    size_t item_size = sizeof(ros_message->byte7);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _Velinfo__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_c1_driver__msg__Velinfo(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_c1_driver
size_t max_serialized_size_c1_driver__msg__Velinfo(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: idsend
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: byte0
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: byte1
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: byte2
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: byte3
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: byte4
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: byte5
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: byte6
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: byte7
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = c1_driver__msg__Velinfo;
    is_plain =
      (
      offsetof(DataType, byte7) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _Velinfo__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_c1_driver__msg__Velinfo(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_Velinfo = {
  "c1_driver::msg",
  "Velinfo",
  _Velinfo__cdr_serialize,
  _Velinfo__cdr_deserialize,
  _Velinfo__get_serialized_size,
  _Velinfo__max_serialized_size
};

static rosidl_message_type_support_t _Velinfo__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Velinfo,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, c1_driver, msg, Velinfo)() {
  return &_Velinfo__type_support;
}

#if defined(__cplusplus)
}
#endif
