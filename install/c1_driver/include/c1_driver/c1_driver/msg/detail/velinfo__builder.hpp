// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from c1_driver:msg/Velinfo.idl
// generated code does not contain a copyright notice

#ifndef C1_DRIVER__MSG__DETAIL__VELINFO__BUILDER_HPP_
#define C1_DRIVER__MSG__DETAIL__VELINFO__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "c1_driver/msg/detail/velinfo__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace c1_driver
{

namespace msg
{

namespace builder
{

class Init_Velinfo_byte7
{
public:
  explicit Init_Velinfo_byte7(::c1_driver::msg::Velinfo & msg)
  : msg_(msg)
  {}
  ::c1_driver::msg::Velinfo byte7(::c1_driver::msg::Velinfo::_byte7_type arg)
  {
    msg_.byte7 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::c1_driver::msg::Velinfo msg_;
};

class Init_Velinfo_byte6
{
public:
  explicit Init_Velinfo_byte6(::c1_driver::msg::Velinfo & msg)
  : msg_(msg)
  {}
  Init_Velinfo_byte7 byte6(::c1_driver::msg::Velinfo::_byte6_type arg)
  {
    msg_.byte6 = std::move(arg);
    return Init_Velinfo_byte7(msg_);
  }

private:
  ::c1_driver::msg::Velinfo msg_;
};

class Init_Velinfo_byte5
{
public:
  explicit Init_Velinfo_byte5(::c1_driver::msg::Velinfo & msg)
  : msg_(msg)
  {}
  Init_Velinfo_byte6 byte5(::c1_driver::msg::Velinfo::_byte5_type arg)
  {
    msg_.byte5 = std::move(arg);
    return Init_Velinfo_byte6(msg_);
  }

private:
  ::c1_driver::msg::Velinfo msg_;
};

class Init_Velinfo_byte4
{
public:
  explicit Init_Velinfo_byte4(::c1_driver::msg::Velinfo & msg)
  : msg_(msg)
  {}
  Init_Velinfo_byte5 byte4(::c1_driver::msg::Velinfo::_byte4_type arg)
  {
    msg_.byte4 = std::move(arg);
    return Init_Velinfo_byte5(msg_);
  }

private:
  ::c1_driver::msg::Velinfo msg_;
};

class Init_Velinfo_byte3
{
public:
  explicit Init_Velinfo_byte3(::c1_driver::msg::Velinfo & msg)
  : msg_(msg)
  {}
  Init_Velinfo_byte4 byte3(::c1_driver::msg::Velinfo::_byte3_type arg)
  {
    msg_.byte3 = std::move(arg);
    return Init_Velinfo_byte4(msg_);
  }

private:
  ::c1_driver::msg::Velinfo msg_;
};

class Init_Velinfo_byte2
{
public:
  explicit Init_Velinfo_byte2(::c1_driver::msg::Velinfo & msg)
  : msg_(msg)
  {}
  Init_Velinfo_byte3 byte2(::c1_driver::msg::Velinfo::_byte2_type arg)
  {
    msg_.byte2 = std::move(arg);
    return Init_Velinfo_byte3(msg_);
  }

private:
  ::c1_driver::msg::Velinfo msg_;
};

class Init_Velinfo_byte1
{
public:
  explicit Init_Velinfo_byte1(::c1_driver::msg::Velinfo & msg)
  : msg_(msg)
  {}
  Init_Velinfo_byte2 byte1(::c1_driver::msg::Velinfo::_byte1_type arg)
  {
    msg_.byte1 = std::move(arg);
    return Init_Velinfo_byte2(msg_);
  }

private:
  ::c1_driver::msg::Velinfo msg_;
};

class Init_Velinfo_byte0
{
public:
  explicit Init_Velinfo_byte0(::c1_driver::msg::Velinfo & msg)
  : msg_(msg)
  {}
  Init_Velinfo_byte1 byte0(::c1_driver::msg::Velinfo::_byte0_type arg)
  {
    msg_.byte0 = std::move(arg);
    return Init_Velinfo_byte1(msg_);
  }

private:
  ::c1_driver::msg::Velinfo msg_;
};

class Init_Velinfo_idsend
{
public:
  Init_Velinfo_idsend()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Velinfo_byte0 idsend(::c1_driver::msg::Velinfo::_idsend_type arg)
  {
    msg_.idsend = std::move(arg);
    return Init_Velinfo_byte0(msg_);
  }

private:
  ::c1_driver::msg::Velinfo msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::c1_driver::msg::Velinfo>()
{
  return c1_driver::msg::builder::Init_Velinfo_idsend();
}

}  // namespace c1_driver

#endif  // C1_DRIVER__MSG__DETAIL__VELINFO__BUILDER_HPP_
