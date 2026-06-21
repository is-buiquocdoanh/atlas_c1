# generated from rosidl_generator_py/resource/_idl.py.em
# with input from c1_driver:msg/Velinfo.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Velinfo(type):
    """Metaclass of message 'Velinfo'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('c1_driver')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'c1_driver.msg.Velinfo')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__velinfo
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__velinfo
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__velinfo
            cls._TYPE_SUPPORT = module.type_support_msg__msg__velinfo
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__velinfo

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Velinfo(metaclass=Metaclass_Velinfo):
    """Message class 'Velinfo'."""

    __slots__ = [
        '_idsend',
        '_byte0',
        '_byte1',
        '_byte2',
        '_byte3',
        '_byte4',
        '_byte5',
        '_byte6',
        '_byte7',
    ]

    _fields_and_field_types = {
        'idsend': 'uint32',
        'byte0': 'uint8',
        'byte1': 'uint8',
        'byte2': 'uint8',
        'byte3': 'uint8',
        'byte4': 'uint8',
        'byte5': 'uint8',
        'byte6': 'uint8',
        'byte7': 'uint8',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.idsend = kwargs.get('idsend', int())
        self.byte0 = kwargs.get('byte0', int())
        self.byte1 = kwargs.get('byte1', int())
        self.byte2 = kwargs.get('byte2', int())
        self.byte3 = kwargs.get('byte3', int())
        self.byte4 = kwargs.get('byte4', int())
        self.byte5 = kwargs.get('byte5', int())
        self.byte6 = kwargs.get('byte6', int())
        self.byte7 = kwargs.get('byte7', int())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.idsend != other.idsend:
            return False
        if self.byte0 != other.byte0:
            return False
        if self.byte1 != other.byte1:
            return False
        if self.byte2 != other.byte2:
            return False
        if self.byte3 != other.byte3:
            return False
        if self.byte4 != other.byte4:
            return False
        if self.byte5 != other.byte5:
            return False
        if self.byte6 != other.byte6:
            return False
        if self.byte7 != other.byte7:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def idsend(self):
        """Message field 'idsend'."""
        return self._idsend

    @idsend.setter
    def idsend(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'idsend' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'idsend' field must be an unsigned integer in [0, 4294967295]"
        self._idsend = value

    @builtins.property
    def byte0(self):
        """Message field 'byte0'."""
        return self._byte0

    @byte0.setter
    def byte0(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'byte0' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'byte0' field must be an unsigned integer in [0, 255]"
        self._byte0 = value

    @builtins.property
    def byte1(self):
        """Message field 'byte1'."""
        return self._byte1

    @byte1.setter
    def byte1(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'byte1' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'byte1' field must be an unsigned integer in [0, 255]"
        self._byte1 = value

    @builtins.property
    def byte2(self):
        """Message field 'byte2'."""
        return self._byte2

    @byte2.setter
    def byte2(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'byte2' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'byte2' field must be an unsigned integer in [0, 255]"
        self._byte2 = value

    @builtins.property
    def byte3(self):
        """Message field 'byte3'."""
        return self._byte3

    @byte3.setter
    def byte3(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'byte3' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'byte3' field must be an unsigned integer in [0, 255]"
        self._byte3 = value

    @builtins.property
    def byte4(self):
        """Message field 'byte4'."""
        return self._byte4

    @byte4.setter
    def byte4(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'byte4' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'byte4' field must be an unsigned integer in [0, 255]"
        self._byte4 = value

    @builtins.property
    def byte5(self):
        """Message field 'byte5'."""
        return self._byte5

    @byte5.setter
    def byte5(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'byte5' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'byte5' field must be an unsigned integer in [0, 255]"
        self._byte5 = value

    @builtins.property
    def byte6(self):
        """Message field 'byte6'."""
        return self._byte6

    @byte6.setter
    def byte6(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'byte6' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'byte6' field must be an unsigned integer in [0, 255]"
        self._byte6 = value

    @builtins.property
    def byte7(self):
        """Message field 'byte7'."""
        return self._byte7

    @byte7.setter
    def byte7(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'byte7' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'byte7' field must be an unsigned integer in [0, 255]"
        self._byte7 = value
