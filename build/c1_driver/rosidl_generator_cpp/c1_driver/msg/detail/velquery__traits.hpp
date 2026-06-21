// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from c1_driver:msg/Velquery.idl
// generated code does not contain a copyright notice

#ifndef C1_DRIVER__MSG__DETAIL__VELQUERY__TRAITS_HPP_
#define C1_DRIVER__MSG__DETAIL__VELQUERY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "c1_driver/msg/detail/velquery__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace c1_driver
{

namespace msg
{

inline void to_flow_style_yaml(
  const Velquery & msg,
  std::ostream & out)
{
  out << "{";
  // member: id
  {
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << ", ";
  }

  // member: byte0
  {
    out << "byte0: ";
    rosidl_generator_traits::value_to_yaml(msg.byte0, out);
    out << ", ";
  }

  // member: byte1
  {
    out << "byte1: ";
    rosidl_generator_traits::value_to_yaml(msg.byte1, out);
    out << ", ";
  }

  // member: byte2
  {
    out << "byte2: ";
    rosidl_generator_traits::value_to_yaml(msg.byte2, out);
    out << ", ";
  }

  // member: byte3
  {
    out << "byte3: ";
    rosidl_generator_traits::value_to_yaml(msg.byte3, out);
    out << ", ";
  }

  // member: byte4
  {
    out << "byte4: ";
    rosidl_generator_traits::value_to_yaml(msg.byte4, out);
    out << ", ";
  }

  // member: byte5
  {
    out << "byte5: ";
    rosidl_generator_traits::value_to_yaml(msg.byte5, out);
    out << ", ";
  }

  // member: byte6
  {
    out << "byte6: ";
    rosidl_generator_traits::value_to_yaml(msg.byte6, out);
    out << ", ";
  }

  // member: byte7
  {
    out << "byte7: ";
    rosidl_generator_traits::value_to_yaml(msg.byte7, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Velquery & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << "\n";
  }

  // member: byte0
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "byte0: ";
    rosidl_generator_traits::value_to_yaml(msg.byte0, out);
    out << "\n";
  }

  // member: byte1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "byte1: ";
    rosidl_generator_traits::value_to_yaml(msg.byte1, out);
    out << "\n";
  }

  // member: byte2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "byte2: ";
    rosidl_generator_traits::value_to_yaml(msg.byte2, out);
    out << "\n";
  }

  // member: byte3
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "byte3: ";
    rosidl_generator_traits::value_to_yaml(msg.byte3, out);
    out << "\n";
  }

  // member: byte4
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "byte4: ";
    rosidl_generator_traits::value_to_yaml(msg.byte4, out);
    out << "\n";
  }

  // member: byte5
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "byte5: ";
    rosidl_generator_traits::value_to_yaml(msg.byte5, out);
    out << "\n";
  }

  // member: byte6
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "byte6: ";
    rosidl_generator_traits::value_to_yaml(msg.byte6, out);
    out << "\n";
  }

  // member: byte7
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "byte7: ";
    rosidl_generator_traits::value_to_yaml(msg.byte7, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Velquery & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace c1_driver

namespace rosidl_generator_traits
{

[[deprecated("use c1_driver::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const c1_driver::msg::Velquery & msg,
  std::ostream & out, size_t indentation = 0)
{
  c1_driver::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use c1_driver::msg::to_yaml() instead")]]
inline std::string to_yaml(const c1_driver::msg::Velquery & msg)
{
  return c1_driver::msg::to_yaml(msg);
}

template<>
inline const char * data_type<c1_driver::msg::Velquery>()
{
  return "c1_driver::msg::Velquery";
}

template<>
inline const char * name<c1_driver::msg::Velquery>()
{
  return "c1_driver/msg/Velquery";
}

template<>
struct has_fixed_size<c1_driver::msg::Velquery>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<c1_driver::msg::Velquery>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<c1_driver::msg::Velquery>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // C1_DRIVER__MSG__DETAIL__VELQUERY__TRAITS_HPP_
