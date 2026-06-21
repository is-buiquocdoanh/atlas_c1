#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to c1_driver__msg__Velinfo

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Velinfo::default())
  }
}

impl rosidl_runtime_rs::Message for Velinfo {
  type RmwMsg = super::msg::rmw::Velinfo;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        idsend: msg.idsend,
        byte0: msg.byte0,
        byte1: msg.byte1,
        byte2: msg.byte2,
        byte3: msg.byte3,
        byte4: msg.byte4,
        byte5: msg.byte5,
        byte6: msg.byte6,
        byte7: msg.byte7,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      idsend: msg.idsend,
      byte0: msg.byte0,
      byte1: msg.byte1,
      byte2: msg.byte2,
      byte3: msg.byte3,
      byte4: msg.byte4,
      byte5: msg.byte5,
      byte6: msg.byte6,
      byte7: msg.byte7,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      idsend: msg.idsend,
      byte0: msg.byte0,
      byte1: msg.byte1,
      byte2: msg.byte2,
      byte3: msg.byte3,
      byte4: msg.byte4,
      byte5: msg.byte5,
      byte6: msg.byte6,
      byte7: msg.byte7,
    }
  }
}


// Corresponds to c1_driver__msg__Velquery

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Velquery::default())
  }
}

impl rosidl_runtime_rs::Message for Velquery {
  type RmwMsg = super::msg::rmw::Velquery;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        id: msg.id,
        byte0: msg.byte0,
        byte1: msg.byte1,
        byte2: msg.byte2,
        byte3: msg.byte3,
        byte4: msg.byte4,
        byte5: msg.byte5,
        byte6: msg.byte6,
        byte7: msg.byte7,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      id: msg.id,
      byte0: msg.byte0,
      byte1: msg.byte1,
      byte2: msg.byte2,
      byte3: msg.byte3,
      byte4: msg.byte4,
      byte5: msg.byte5,
      byte6: msg.byte6,
      byte7: msg.byte7,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      id: msg.id,
      byte0: msg.byte0,
      byte1: msg.byte1,
      byte2: msg.byte2,
      byte3: msg.byte3,
      byte4: msg.byte4,
      byte5: msg.byte5,
      byte6: msg.byte6,
      byte7: msg.byte7,
    }
  }
}


