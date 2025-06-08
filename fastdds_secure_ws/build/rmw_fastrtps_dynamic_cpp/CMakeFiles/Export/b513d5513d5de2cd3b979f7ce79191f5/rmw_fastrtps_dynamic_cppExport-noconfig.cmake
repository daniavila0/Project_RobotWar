#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "rmw_fastrtps_dynamic_cpp::rmw_fastrtps_dynamic_cpp" for configuration ""
set_property(TARGET rmw_fastrtps_dynamic_cpp::rmw_fastrtps_dynamic_cpp APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(rmw_fastrtps_dynamic_cpp::rmw_fastrtps_dynamic_cpp PROPERTIES
  IMPORTED_LINK_DEPENDENT_LIBRARIES_NOCONFIG "rmw_dds_common::rmw_dds_common_library;tracetools::tracetools"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/librmw_fastrtps_dynamic_cpp.so"
  IMPORTED_SONAME_NOCONFIG "librmw_fastrtps_dynamic_cpp.so"
  )

list(APPEND _cmake_import_check_targets rmw_fastrtps_dynamic_cpp::rmw_fastrtps_dynamic_cpp )
list(APPEND _cmake_import_check_files_for_rmw_fastrtps_dynamic_cpp::rmw_fastrtps_dynamic_cpp "${_IMPORT_PREFIX}/lib/librmw_fastrtps_dynamic_cpp.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
