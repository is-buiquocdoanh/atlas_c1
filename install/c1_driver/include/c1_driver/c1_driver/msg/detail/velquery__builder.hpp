// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from c1_driver:msg/Velquery.idl
// generated code does not contain a copyright notice

#ifndef C1_DRIVER__MSG__DETAIL__VELQUERY__BUILDER_HPP_
#define C1_DRIVER__MSG__DETAIL__VELQUERY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "c1_driver/msg/detail/velquery__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace c1_driver
{

namespace msg
{

namespace builder
{

class Init_Velquery_byte7
{
public:
  explicit Init_Velquery_byte7(::c1_driver::msg::Velquery & msg)
  : msg_(msg)
  {}
  ::c1_driver::msg::Velquery byte7(::c1_driver::msg::Velquery::_byte7_type arg)
  {
    msg_.byte7 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::c1_driver::msg::Velquery msg_;
};

class Init_Velquery_byte6
{
public:
  explicit Init_Velquery_byte6(::c1_driver::msg::Velquery & msg)
  : msg_(msg)
  {}
  Init_Velquery_byte7 byte6(::c1_driver::msg::Velquery::_byte6_type arg)
  {
    msg_.byte6 = std::move(arg);
    return Init_Velquery_byte7(msg_);
  }

private:
  ::c1_driver::msg::Velquery msg_;
};

class Init_Velquery_byte5
{
public:
  explicit Init_Velquery_byte5(::c1_driver::msg::Velquery & msg)
  : msg_(msg)
  {}
  Init_Velquery_byte6 byte5(::c1_driver::msg::Velquery::_byte5_type arg)
  {
    msg_.byte5 = std::move(arg);
    return Init_Velquery_byte6(msg_);
  }

private:
  ::c1_driver::msg::Velquery msg_;
};

class Init_Velquery_byte4
{
public:
  explicit Init_Velquery_byte4(::c1_driver::msg::Velquery & msg)
  : msg_(msg)
  {}
  Init_Velquery_byte5 byte4(::c1_driver::msg::Velquery::_byte4_type arg)
  {
    msg_.byte4 = std::move(arg);
    return Init_Velquery_byte5(msg_);
  }

private:
  ::c1_driver::msg::Velquery msg_;
};

class Init_Velquery_byte3
{
public:
  explicit Init_Velquery_byte3(::c1_driver::msg::Velquery & msg)
  : msg_(msg)
  {}
  Init_Velquery_byte4 byte3(::c1_driver::msg::Velquery::_byte3_type arg)
  {
    msg_.byte3 = std::move(arg);
    return Init_Velquery_byte4(msg_);
  }

private:
  ::c1_driver::msg::Velquery msg_;
};

class Init_Velquery_byte2
{
public:
  explicit Init_Velquery_byte2(::c1_driver::msg::Velquery & msg)
  : msg_(msg)
  {}
  Init_Velquery_byte3 byte2(::c1_driver::msg::Velquery::_byte2_type arg)
  {
    msg_.byte2 = std::move(arg);
    return Init_Velquery_byte3(msg_);
  }

private:
  ::c1_driver::msg::Velquery msg_;
};

class Init_Velquery_byte1
{
public:
  explicit Init_Velquery_byte1(::c1_driver::msg::Velquery & msg)
  : msg_(msg)
  {}
  Init_Velquery_byte2 byte1(::c1_driver::msg::Velquery::_byte1_type arg)
  {
    msg_.byte1 = std::move(arg);
    return Init_Velquery_byte2(msg_);
  }

private:
  ::c1_driver::msg::Velquery msg_;
};

class Init_Velquery_byte0
{
public:
  explicit Init_Velquery_byte0(::c1_driver::msg::Velquery & msg)
  : msg_(msg)
  {}
  Init_Velquery_byte1 byte0(::c1_driver::msg::Velquery::_byte0_type arg)
  {
    msg_.byte0 = std::move(arg);
    return Init_Velquery_byte1(msg_);
  }

private:
  ::c1_driver::msg::Velquery msg_;
};

class Init_Velquery_id
{
public:
  Init_Velquery_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Velquery_byte0 id(::c1_driver::msg::Velquery::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_Velquery_byte0(msg_);
  }

private:
  ::c1_driver::msg::Velquery msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::c1_driver::msg::Velquery>()
{
  return c1_driver::msg::builder::Init_Velquery_id();
}

}  // namespace c1_driver

#endif  // C1_DRIVER__MSG__DETAIL__VELQUERY__BUILDER_HPP_
