#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "c1_driver__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__c1_driver__msg__Velinfo() -> *const std::ffi::c_void;
}

#[link(name = "c1_driver__rosidl_generator_c")]
extern "C" {
    fn c1_driver__msg__Velinfo__init(msg: *mut Velinfo) -> bool;
    fn c1_driver__msg__Velinfo__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Velinfo>, size: usize) -> bool;
    fn c1_driver__msg__Velinfo__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Velinfo>);
    fn c1_driver__msg__Velinfo__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Velinfo>, out_seq: *mut rosidl_runtime_rs::Sequence<Velinfo>) -> bool;
}

// Corresponds to c1_driver__msg__Velinfo
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Velinfo {

    // This member is not documented.
    #[allow(missing_docs)]
    pub idsend: u32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub byte0: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub byte1: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub byte2: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub byte3: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub byte4: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub byte5: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub byte6: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub byte7: u8,

}



impl Default for Velinfo {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !c1_driver__msg__Velinfo__init(&mut msg as *mut _) {
        panic!("Call to c1_driver__msg__Velinfo__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Velinfo {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { c1_driver__msg__Velinfo__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { c1_driver__msg__Velinfo__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { c1_driver__msg__Velinfo__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Velinfo {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Velinfo where Self: Sized {
  const TYPE_NAME: &'static str = "c1_driver/msg/Velinfo";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__c1_driver__msg__Velinfo() }
  }
}


#[link(name = "c1_driver__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__c1_driver__msg__Velquery() -> *const std::ffi::c_void;
}

#[link(name = "c1_driver__rosidl_generator_c")]
extern "C" {
    fn c1_driver__msg__Velquery__init(msg: *mut Velquery) -> bool;
    fn c1_driver__msg__Velquery__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Velquery>, size: usize) -> bool;
    fn c1_driver__msg__Velquery__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Velquery>);
    fn c1_driver__msg__Velquery__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Velquery>, out_seq: *mut rosidl_runtime_rs::Sequence<Velquery>) -> bool;
}

// Corresponds to c1_driver__msg__Velquery
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Velquery {

    // This member is not documented.
    #[allow(missing_docs)]
    pub id: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub byte0: i16,


    // This member is not documented.
    #[allow(missing_docs)]
    pub byte1: i16,


    // This member is not documented.
    #[allow(missing_docs)]
    pub byte2: i16,


    // This member is not documented.
    #[allow(missing_docs)]
    pub byte3: i16,


    // This member is not documented.
    #[allow(missing_docs)]
    pub byte4: i16,


    // This member is not documented.
    #[allow(missing_docs)]
    pub byte5: i16,


    // This member is not documented.
    #[allow(missing_docs)]
    pub byte6: i16,


    // This member is not documented.
    #[allow(missing_docs)]
    pub byte7: i16,

}



impl Default for Velquery {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !c1_driver__msg__Velquery__init(&mut msg as *mut _) {
        panic!("Call to c1_driver__msg__Velquery__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Velquery {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { c1_driver__msg__Velquery__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { c1_driver__msg__Velquery__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { c1_driver__msg__Velquery__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Velquery {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Velquery where Self: Sized {
  const TYPE_NAME: &'static str = "c1_driver/msg/Velquery";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__c1_driver__msg__Velquery() }
  }
}


