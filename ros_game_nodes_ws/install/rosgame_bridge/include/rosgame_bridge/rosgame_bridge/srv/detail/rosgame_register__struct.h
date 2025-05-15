// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rosgame_bridge:srv/RosgameRegister.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rosgame_bridge/srv/rosgame_register.h"


#ifndef ROSGAME_BRIDGE__SRV__DETAIL__ROSGAME_REGISTER__STRUCT_H_
#define ROSGAME_BRIDGE__SRV__DETAIL__ROSGAME_REGISTER__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'username'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/RosgameRegister in the package rosgame_bridge.
typedef struct rosgame_bridge__srv__RosgameRegister_Request
{
  rosidl_runtime_c__String username;
} rosgame_bridge__srv__RosgameRegister_Request;

// Struct for a sequence of rosgame_bridge__srv__RosgameRegister_Request.
typedef struct rosgame_bridge__srv__RosgameRegister_Request__Sequence
{
  rosgame_bridge__srv__RosgameRegister_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rosgame_bridge__srv__RosgameRegister_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'robot_name'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/RosgameRegister in the package rosgame_bridge.
typedef struct rosgame_bridge__srv__RosgameRegister_Response
{
  rosidl_runtime_c__String robot_name;
} rosgame_bridge__srv__RosgameRegister_Response;

// Struct for a sequence of rosgame_bridge__srv__RosgameRegister_Response.
typedef struct rosgame_bridge__srv__RosgameRegister_Response__Sequence
{
  rosgame_bridge__srv__RosgameRegister_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rosgame_bridge__srv__RosgameRegister_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  rosgame_bridge__srv__RosgameRegister_Event__request__MAX_SIZE = 1
};
// response
enum
{
  rosgame_bridge__srv__RosgameRegister_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/RosgameRegister in the package rosgame_bridge.
typedef struct rosgame_bridge__srv__RosgameRegister_Event
{
  service_msgs__msg__ServiceEventInfo info;
  rosgame_bridge__srv__RosgameRegister_Request__Sequence request;
  rosgame_bridge__srv__RosgameRegister_Response__Sequence response;
} rosgame_bridge__srv__RosgameRegister_Event;

// Struct for a sequence of rosgame_bridge__srv__RosgameRegister_Event.
typedef struct rosgame_bridge__srv__RosgameRegister_Event__Sequence
{
  rosgame_bridge__srv__RosgameRegister_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rosgame_bridge__srv__RosgameRegister_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROSGAME_BRIDGE__SRV__DETAIL__ROSGAME_REGISTER__STRUCT_H_
