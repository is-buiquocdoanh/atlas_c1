// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from c1_driver:msg/Velinfo.idl
// generated code does not contain a copyright notice

#ifndef C1_DRIVER__MSG__DETAIL__VELINFO__STRUCT_HPP_
#define C1_DRIVER__MSG__DETAIL__VELINFO__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__c1_driver__msg__Velinfo __attribute__((deprecated))
#else
# define DEPRECATED__c1_driver__msg__Velinfo __declspec(deprecated)
#endif

namespace c1_driver
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Velinfo_
{
  using Type = Velinfo_<ContainerAllocator>;

  explicit Velinfo_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->idsend = 0ul;
      this->byte0 = 0;
      this->byte1 = 0;
      this->byte2 = 0;
      this->byte3 = 0;
      this->byte4 = 0;
      this->byte5 = 0;
      this->byte6 = 0;
      this->byte7 = 0;
    }
  }

  explicit Velinfo_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->idsend = 0ul;
      this->byte0 = 0;
      this->byte1 = 0;
      this->byte2 = 0;
      this->byte3 = 0;
      this->byte4 = 0;
      this->byte5 = 0;
      this->byte6 = 0;
      this->byte7 = 0;
    }
  }

  // field types and members
  using _idsend_type =
    uint32_t;
  _idsend_type idsend;
  using _byte0_type =
    uint8_t;
  _byte0_type byte0;
  using _byte1_type =
    uint8_t;
  _byte1_type byte1;
  using _byte2_type =
    uint8_t;
  _byte2_type byte2;
  using _byte3_type =
    uint8_t;
  _byte3_type byte3;
  using _byte4_type =
    uint8_t;
  _byte4_type byte4;
  using _byte5_type =
    uint8_t;
  _byte5_type byte5;
  using _byte6_type =
    uint8_t;
  _byte6_type byte6;
  using _byte7_type =
    uint8_t;
  _byte7_type byte7;

  // setters for named parameter idiom
  Type & set__idsend(
    const uint32_t & _arg)
  {
    this->idsend = _arg;
    return *this;
  }
  Type & set__byte0(
    const uint8_t & _arg)
  {
    this->byte0 = _arg;
    return *this;
  }
  Type & set__byte1(
    const uint8_t & _arg)
  {
    this->byte1 = _arg;
    return *this;
  }
  Type & set__byte2(
    const uint8_t & _arg)
  {
    this->byte2 = _arg;
    return *this;
  }
  Type & set__byte3(
    const uint8_t & _arg)
  {
    this->byte3 = _arg;
    return *this;
  }
  Type & set__byte4(
    const uint8_t & _arg)
  {
    this->byte4 = _arg;
    return *this;
  }
  Type & set__byte5(
    const uint8_t & _arg)
  {
    this->byte5 = _arg;
    return *this;
  }
  Type & set__byte6(
    const uint8_t & _arg)
  {
    this->byte6 = _arg;
    return *this;
  }
  Type & set__byte7(
    const uint8_t & _arg)
  {
    this->byte7 = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    c1_driver::msg::Velinfo_<ContainerAllocator> *;
  using ConstRawPtr =
    const c1_driver::msg::Velinfo_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<c1_driver::msg::Velinfo_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<c1_driver::msg::Velinfo_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      c1_driver::msg::Velinfo_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<c1_driver::msg::Velinfo_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      c1_driver::msg::Velinfo_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<c1_driver::msg::Velinfo_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<c1_driver::msg::Velinfo_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<c1_driver::msg::Velinfo_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__c1_driver__msg__Velinfo
    std::shared_ptr<c1_driver::msg::Velinfo_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__c1_driver__msg__Velinfo
    std::shared_ptr<c1_driver::msg::Velinfo_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Velinfo_ & other) const
  {
    if (this->idsend != other.idsend) {
      return false;
    }
    if (this->byte0 != other.byte0) {
      return false;
    }
    if (this->byte1 != other.byte1) {
      return false;
    }
    if (this->byte2 != other.byte2) {
      return false;
    }
    if (this->byte3 != other.byte3) {
      return false;
    }
    if (this->byte4 != other.byte4) {
      return false;
    }
    if (this->byte5 != other.byte5) {
      return false;
    }
    if (this->byte6 != other.byte6) {
      return false;
    }
    if (this->byte7 != other.byte7) {
      return false;
    }
    return true;
  }
  bool operator!=(const Velinfo_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Velinfo_

// alias to use template instance with default allocator
using Velinfo =
  c1_driver::msg::Velinfo_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace c1_driver

#endif  // C1_DRIVER__MSG__DETAIL__VELINFO__STRUCT_HPP_
