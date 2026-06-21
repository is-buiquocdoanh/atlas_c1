// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from c1_driver:msg/Velquery.idl
// generated code does not contain a copyright notice
#include "c1_driver/msg/detail/velquery__rosidl_typesupport_fastrtps_cpp.hpp"
#include "c1_driver/msg/detail/velquery__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace c1_driver
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_c1_driver
cdr_serialize(
  const c1_driver::msg::Velquery & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: id
  cdr << ros_message.id;
  // Member: byte0
  cdr << ros_message.byte0;
  // Member: byte1
  cdr << ros_message.byte1;
  // Member: byte2
  cdr << ros_message.byte2;
  // Member: byte3
  cdr << ros_message.byte3;
  // Member: byte4
  cdr << ros_message.byte4;
  // Member: byte5
  cdr << ros_message.byte5;
  // Member: byte6
  cdr << ros_message.byte6;
  // Member: byte7
  cdr << ros_message.byte7;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_c1_driver
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  c1_driver::msg::Velquery & ros_message)
{
  // Member: id
  cdr >> ros_message.id;

  // Member: byte0
  cdr >> ros_message.byte0;

  // Member: byte1
  cdr >> ros_message.byte1;

  // Member: byte2
  cdr >> ros_message.byte2;

  // Member: byte3
  cdr >> ros_message.byte3;

  // Member: byte4
  cdr >> ros_message.byte4;

  // Member: byte5
  cdr >> ros_message.byte5;

  // Member: byte6
  cdr >> ros_message.byte6;

  // Member: byte7
  cdr >> ros_message.byte7;

  return true;
}  // NOLINT(readability/fn_size)

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_c1_driver
get_serialized_size(
  const c1_driver::msg::Velquery & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: id
  {
    size_t item_size = sizeof(ros_message.id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: byte0
  {
    size_t item_size = sizeof(ros_message.byte0);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: byte1
  {
    size_t item_size = sizeof(ros_message.byte1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: byte2
  {
    size_t item_size = sizeof(ros_message.byte2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: byte3
  {
    size_t item_size = sizeof(ros_message.byte3);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: byte4
  {
    size_t item_size = sizeof(ros_message.byte4);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: byte5
  {
    size_t item_size = sizeof(ros_message.byte5);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: byte6
  {
    size_t item_size = sizeof(ros_message.byte6);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: byte7
  {
    size_t item_size = sizeof(ros_message.byte7);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_c1_driver
max_serialized_size_Velquery(
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


  // Member: id
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: byte0
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: byte1
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: byte2
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: byte3
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: byte4
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: byte5
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: byte6
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: byte7
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = c1_driver::msg::Velquery;
    is_plain =
      (
      offsetof(DataType, byte7) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _Velquery__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const c1_driver::msg::Velquery *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _Velquery__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<c1_driver::msg::Velquery *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _Velquery__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const c1_driver::msg::Velquery *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _Velquery__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_Velquery(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _Velquery__callbacks = {
  "c1_driver::msg",
  "Velquery",
  _Velquery__cdr_serialize,
  _Velquery__cdr_deserialize,
  _Velquery__get_serialized_size,
  _Velquery__max_serialized_size
};

static rosidl_message_type_support_t _Velquery__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_Velquery__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace c1_driver

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_c1_driver
const rosidl_message_type_support_t *
get_message_type_support_handle<c1_driver::msg::Velquery>()
{
  return &c1_driver::msg::typesupport_fastrtps_cpp::_Velquery__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, c1_driver, msg, Velquery)() {
  return &c1_driver::msg::typesupport_fastrtps_cpp::_Velquery__handle;
}

#ifdef __cplusplus
}
#endif
