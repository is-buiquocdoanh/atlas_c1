# generated from
# rosidl_cmake/cmake/template/rosidl_cmake_export_typesupport_targets.cmake.in

set(_exported_typesupport_targets
  "__rosidl_generator_c:c1_driver__rosidl_generator_c;__rosidl_typesupport_fastrtps_c:c1_driver__rosidl_typesupport_fastrtps_c;__rosidl_typesupport_introspection_c:c1_driver__rosidl_typesupport_introspection_c;__rosidl_typesupport_c:c1_driver__rosidl_typesupport_c;__rosidl_generator_cpp:c1_driver__rosidl_generator_cpp;__rosidl_typesupport_fastrtps_cpp:c1_driver__rosidl_typesupport_fastrtps_cpp;__rosidl_typesupport_introspection_cpp:c1_driver__rosidl_typesupport_introspection_cpp;__rosidl_typesupport_cpp:c1_driver__rosidl_typesupport_cpp;__rosidl_generator_py:c1_driver__rosidl_generator_py")

# populate c1_driver_TARGETS_<suffix>
if(NOT _exported_typesupport_targets STREQUAL "")
  # loop over typesupport targets
  foreach(_tuple ${_exported_typesupport_targets})
    string(REPLACE ":" ";" _tuple "${_tuple}")
    list(GET _tuple 0 _suffix)
    list(GET _tuple 1 _target)

    set(_target "c1_driver::${_target}")
    if(NOT TARGET "${_target}")
      # the exported target must exist
      message(WARNING "Package 'c1_driver' exports the typesupport target '${_target}' which doesn't exist")
    else()
      list(APPEND c1_driver_TARGETS${_suffix} "${_target}")
    endif()
  endforeach()
endif()
