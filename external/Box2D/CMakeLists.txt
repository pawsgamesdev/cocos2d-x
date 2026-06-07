cmake_minimum_required(VERSION 3.6)

set(lib_name box2d)
set(target_name ext_${lib_name})

project(${lib_name})

include(../cmake/CocosExternalConfig.cmake)

add_library(${target_name} STATIC IMPORTED GLOBAL)

set_target_properties(${target_name} PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

if(WINDOWS)
  set(_box2d_prebuilt "${CMAKE_CURRENT_SOURCE_DIR}/prebuilt/win32")
  set_target_properties(${target_name} PROPERTIES
    IMPORTED_LOCATION         "${_box2d_prebuilt}/release/lib${lib_name}.lib"
    IMPORTED_LOCATION_DEBUG   "${_box2d_prebuilt}/debug/lib${lib_name}.lib"
    IMPORTED_LOCATION_RELEASE "${_box2d_prebuilt}/release/lib${lib_name}.lib"
  )
else()
  set_target_properties(${target_name} PROPERTIES
    IMPORTED_LOCATION "${platform_spec_path}/lib${lib_name}.a"
  )
endif()
