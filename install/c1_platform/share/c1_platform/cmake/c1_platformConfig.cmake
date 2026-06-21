# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_c1_platform_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED c1_platform_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(c1_platform_FOUND FALSE)
  elseif(NOT c1_platform_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(c1_platform_FOUND FALSE)
  endif()
  return()
endif()
set(_c1_platform_CONFIG_INCLUDED TRUE)

# output package information
if(NOT c1_platform_FIND_QUIETLY)
  message(STATUS "Found c1_platform: 0.0.0 (${c1_platform_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'c1_platform' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${c1_platform_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(c1_platform_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${c1_platform_DIR}/${_extra}")
endforeach()
