// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from c1_driver:msg/Velinfo.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "c1_driver/msg/detail/velinfo__struct.h"
#include "c1_driver/msg/detail/velinfo__type_support.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace c1_driver
{

namespace msg
{

namespace rosidl_typesupport_c
{

typedef struct _Velinfo_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Velinfo_type_support_ids_t;

static const _Velinfo_type_support_ids_t _Velinfo_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Velinfo_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Velinfo_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Velinfo_type_support_symbol_names_t _Velinfo_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, c1_driver, msg, Velinfo)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, c1_driver, msg, Velinfo)),
  }
};

typedef struct _Velinfo_type_support_data_t
{
  void * data[2];
} _Velinfo_type_support_data_t;

static _Velinfo_type_support_data_t _Velinfo_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Velinfo_message_typesupport_map = {
  2,
  "c1_driver",
  &_Velinfo_message_typesupport_ids.typesupport_identifier[0],
  &_Velinfo_message_typesupport_symbol_names.symbol_name[0],
  &_Velinfo_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Velinfo_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Velinfo_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace msg

}  // namespace c1_driver

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, c1_driver, msg, Velinfo)() {
  return &::c1_driver::msg::rosidl_typesupport_c::Velinfo_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
