# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_rosgame_players_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED rosgame_players_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(rosgame_players_FOUND FALSE)
  elseif(NOT rosgame_players_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(rosgame_players_FOUND FALSE)
  endif()
  return()
endif()
set(_rosgame_players_CONFIG_INCLUDED TRUE)

# output package information
if(NOT rosgame_players_FIND_QUIETLY)
  message(STATUS "Found rosgame_players: 0.0.0 (${rosgame_players_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'rosgame_players' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT rosgame_players_DEPRECATED_QUIET)
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(rosgame_players_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${rosgame_players_DIR}/${_extra}")
endforeach()
