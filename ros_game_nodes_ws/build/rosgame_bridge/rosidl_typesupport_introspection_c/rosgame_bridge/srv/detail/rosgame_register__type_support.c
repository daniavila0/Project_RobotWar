// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from rosgame_bridge:srv/RosgameRegister.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "rosgame_bridge/srv/detail/rosgame_register__rosidl_typesupport_introspection_c.h"
#include "rosgame_bridge/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "rosgame_bridge/srv/detail/rosgame_register__functions.h"
#include "rosgame_bridge/srv/detail/rosgame_register__struct.h"


// Include directives for member types
// Member `username`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void rosgame_bridge__srv__RosgameRegister_Request__rosidl_typesupport_introspection_c__RosgameRegister_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  rosgame_bridge__srv__RosgameRegister_Request__init(message_memory);
}

void rosgame_bridge__srv__RosgameRegister_Request__rosidl_typesupport_introspection_c__RosgameRegister_Request_fini_function(void * message_memory)
{
  rosgame_bridge__srv__RosgameRegister_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember rosgame_bridge__srv__RosgameRegister_Request__rosidl_typesupport_introspection_c__RosgameRegister_Request_message_member_array[1] = {
  {
    "username",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rosgame_bridge__srv__RosgameRegister_Request, username),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers rosgame_bridge__srv__RosgameRegister_Request__rosidl_typesupport_introspection_c__RosgameRegister_Request_message_members = {
  "rosgame_bridge__srv",  // message namespace
  "RosgameRegister_Request",  // message name
  1,  // number of fields
  sizeof(rosgame_bridge__srv__RosgameRegister_Request),
  false,  // has_any_key_member_
  rosgame_bridge__srv__RosgameRegister_Request__rosidl_typesupport_introspection_c__RosgameRegister_Request_message_member_array,  // message members
  rosgame_bridge__srv__RosgameRegister_Request__rosidl_typesupport_introspection_c__RosgameRegister_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  rosgame_bridge__srv__RosgameRegister_Request__rosidl_typesupport_introspection_c__RosgameRegister_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t rosgame_bridge__srv__RosgameRegister_Request__rosidl_typesupport_introspection_c__RosgameRegister_Request_message_type_support_handle = {
  0,
  &rosgame_bridge__srv__RosgameRegister_Request__rosidl_typesupport_introspection_c__RosgameRegister_Request_message_members,
  get_message_typesupport_handle_function,
  &rosgame_bridge__srv__RosgameRegister_Request__get_type_hash,
  &rosgame_bridge__srv__RosgameRegister_Request__get_type_description,
  &rosgame_bridge__srv__RosgameRegister_Request__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rosgame_bridge
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rosgame_bridge, srv, RosgameRegister_Request)() {
  if (!rosgame_bridge__srv__RosgameRegister_Request__rosidl_typesupport_introspection_c__RosgameRegister_Request_message_type_support_handle.typesupport_identifier) {
    rosgame_bridge__srv__RosgameRegister_Request__rosidl_typesupport_introspection_c__RosgameRegister_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &rosgame_bridge__srv__RosgameRegister_Request__rosidl_typesupport_introspection_c__RosgameRegister_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "rosgame_bridge/srv/detail/rosgame_register__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosgame_bridge/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "rosgame_bridge/srv/detail/rosgame_register__functions.h"
// already included above
// #include "rosgame_bridge/srv/detail/rosgame_register__struct.h"


// Include directives for member types
// Member `robot_name`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void rosgame_bridge__srv__RosgameRegister_Response__rosidl_typesupport_introspection_c__RosgameRegister_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  rosgame_bridge__srv__RosgameRegister_Response__init(message_memory);
}

void rosgame_bridge__srv__RosgameRegister_Response__rosidl_typesupport_introspection_c__RosgameRegister_Response_fini_function(void * message_memory)
{
  rosgame_bridge__srv__RosgameRegister_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember rosgame_bridge__srv__RosgameRegister_Response__rosidl_typesupport_introspection_c__RosgameRegister_Response_message_member_array[1] = {
  {
    "robot_name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rosgame_bridge__srv__RosgameRegister_Response, robot_name),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers rosgame_bridge__srv__RosgameRegister_Response__rosidl_typesupport_introspection_c__RosgameRegister_Response_message_members = {
  "rosgame_bridge__srv",  // message namespace
  "RosgameRegister_Response",  // message name
  1,  // number of fields
  sizeof(rosgame_bridge__srv__RosgameRegister_Response),
  false,  // has_any_key_member_
  rosgame_bridge__srv__RosgameRegister_Response__rosidl_typesupport_introspection_c__RosgameRegister_Response_message_member_array,  // message members
  rosgame_bridge__srv__RosgameRegister_Response__rosidl_typesupport_introspection_c__RosgameRegister_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  rosgame_bridge__srv__RosgameRegister_Response__rosidl_typesupport_introspection_c__RosgameRegister_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t rosgame_bridge__srv__RosgameRegister_Response__rosidl_typesupport_introspection_c__RosgameRegister_Response_message_type_support_handle = {
  0,
  &rosgame_bridge__srv__RosgameRegister_Response__rosidl_typesupport_introspection_c__RosgameRegister_Response_message_members,
  get_message_typesupport_handle_function,
  &rosgame_bridge__srv__RosgameRegister_Response__get_type_hash,
  &rosgame_bridge__srv__RosgameRegister_Response__get_type_description,
  &rosgame_bridge__srv__RosgameRegister_Response__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rosgame_bridge
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rosgame_bridge, srv, RosgameRegister_Response)() {
  if (!rosgame_bridge__srv__RosgameRegister_Response__rosidl_typesupport_introspection_c__RosgameRegister_Response_message_type_support_handle.typesupport_identifier) {
    rosgame_bridge__srv__RosgameRegister_Response__rosidl_typesupport_introspection_c__RosgameRegister_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &rosgame_bridge__srv__RosgameRegister_Response__rosidl_typesupport_introspection_c__RosgameRegister_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "rosgame_bridge/srv/detail/rosgame_register__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosgame_bridge/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "rosgame_bridge/srv/detail/rosgame_register__functions.h"
// already included above
// #include "rosgame_bridge/srv/detail/rosgame_register__struct.h"


// Include directives for member types
// Member `info`
#include "service_msgs/msg/service_event_info.h"
// Member `info`
#include "service_msgs/msg/detail/service_event_info__rosidl_typesupport_introspection_c.h"
// Member `request`
// Member `response`
#include "rosgame_bridge/srv/rosgame_register.h"
// Member `request`
// Member `response`
// already included above
// #include "rosgame_bridge/srv/detail/rosgame_register__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void rosgame_bridge__srv__RosgameRegister_Event__rosidl_typesupport_introspection_c__RosgameRegister_Event_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  rosgame_bridge__srv__RosgameRegister_Event__init(message_memory);
}

void rosgame_bridge__srv__RosgameRegister_Event__rosidl_typesupport_introspection_c__RosgameRegister_Event_fini_function(void * message_memory)
{
  rosgame_bridge__srv__RosgameRegister_Event__fini(message_memory);
}

size_t rosgame_bridge__srv__RosgameRegister_Event__rosidl_typesupport_introspection_c__size_function__RosgameRegister_Event__request(
  const void * untyped_member)
{
  const rosgame_bridge__srv__RosgameRegister_Request__Sequence * member =
    (const rosgame_bridge__srv__RosgameRegister_Request__Sequence *)(untyped_member);
  return member->size;
}

const void * rosgame_bridge__srv__RosgameRegister_Event__rosidl_typesupport_introspection_c__get_const_function__RosgameRegister_Event__request(
  const void * untyped_member, size_t index)
{
  const rosgame_bridge__srv__RosgameRegister_Request__Sequence * member =
    (const rosgame_bridge__srv__RosgameRegister_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void * rosgame_bridge__srv__RosgameRegister_Event__rosidl_typesupport_introspection_c__get_function__RosgameRegister_Event__request(
  void * untyped_member, size_t index)
{
  rosgame_bridge__srv__RosgameRegister_Request__Sequence * member =
    (rosgame_bridge__srv__RosgameRegister_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void rosgame_bridge__srv__RosgameRegister_Event__rosidl_typesupport_introspection_c__fetch_function__RosgameRegister_Event__request(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const rosgame_bridge__srv__RosgameRegister_Request * item =
    ((const rosgame_bridge__srv__RosgameRegister_Request *)
    rosgame_bridge__srv__RosgameRegister_Event__rosidl_typesupport_introspection_c__get_const_function__RosgameRegister_Event__request(untyped_member, index));
  rosgame_bridge__srv__RosgameRegister_Request * value =
    (rosgame_bridge__srv__RosgameRegister_Request *)(untyped_value);
  *value = *item;
}

void rosgame_bridge__srv__RosgameRegister_Event__rosidl_typesupport_introspection_c__assign_function__RosgameRegister_Event__request(
  void * untyped_member, size_t index, const void * untyped_value)
{
  rosgame_bridge__srv__RosgameRegister_Request * item =
    ((rosgame_bridge__srv__RosgameRegister_Request *)
    rosgame_bridge__srv__RosgameRegister_Event__rosidl_typesupport_introspection_c__get_function__RosgameRegister_Event__request(untyped_member, index));
  const rosgame_bridge__srv__RosgameRegister_Request * value =
    (const rosgame_bridge__srv__RosgameRegister_Request *)(untyped_value);
  *item = *value;
}

bool rosgame_bridge__srv__RosgameRegister_Event__rosidl_typesupport_introspection_c__resize_function__RosgameRegister_Event__request(
  void * untyped_member, size_t size)
{
  rosgame_bridge__srv__RosgameRegister_Request__Sequence * member =
    (rosgame_bridge__srv__RosgameRegister_Request__Sequence *)(untyped_member);
  rosgame_bridge__srv__RosgameRegister_Request__Sequence__fini(member);
  return rosgame_bridge__srv__RosgameRegister_Request__Sequence__init(member, size);
}

size_t rosgame_bridge__srv__RosgameRegister_Event__rosidl_typesupport_introspection_c__size_function__RosgameRegister_Event__response(
  const void * untyped_member)
{
  const rosgame_bridge__srv__RosgameRegister_Response__Sequence * member =
    (const rosgame_bridge__srv__RosgameRegister_Response__Sequence *)(untyped_member);
  return member->size;
}

const void * rosgame_bridge__srv__RosgameRegister_Event__rosidl_typesupport_introspection_c__get_const_function__RosgameRegister_Event__response(
  const void * untyped_member, size_t index)
{
  const rosgame_bridge__srv__RosgameRegister_Response__Sequence * member =
    (const rosgame_bridge__srv__RosgameRegister_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void * rosgame_bridge__srv__RosgameRegister_Event__rosidl_typesupport_introspection_c__get_function__RosgameRegister_Event__response(
  void * untyped_member, size_t index)
{
  rosgame_bridge__srv__RosgameRegister_Response__Sequence * member =
    (rosgame_bridge__srv__RosgameRegister_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void rosgame_bridge__srv__RosgameRegister_Event__rosidl_typesupport_introspection_c__fetch_function__RosgameRegister_Event__response(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const rosgame_bridge__srv__RosgameRegister_Response * item =
    ((const rosgame_bridge__srv__RosgameRegister_Response *)
    rosgame_bridge__srv__RosgameRegister_Event__rosidl_typesupport_introspection_c__get_const_function__RosgameRegister_Event__response(untyped_member, index));
  rosgame_bridge__srv__RosgameRegister_Response * value =
    (rosgame_bridge__srv__RosgameRegister_Response *)(untyped_value);
  *value = *item;
}

void rosgame_bridge__srv__RosgameRegister_Event__rosidl_typesupport_introspection_c__assign_function__RosgameRegister_Event__response(
  void * untyped_member, size_t index, const void * untyped_value)
{
  rosgame_bridge__srv__RosgameRegister_Response * item =
    ((rosgame_bridge__srv__RosgameRegister_Response *)
    rosgame_bridge__srv__RosgameRegister_Event__rosidl_typesupport_introspection_c__get_function__RosgameRegister_Event__response(untyped_member, index));
  const rosgame_bridge__srv__RosgameRegister_Response * value =
    (const rosgame_bridge__srv__RosgameRegister_Response *)(untyped_value);
  *item = *value;
}

bool rosgame_bridge__srv__RosgameRegister_Event__rosidl_typesupport_introspection_c__resize_function__RosgameRegister_Event__response(
  void * untyped_member, size_t size)
{
  rosgame_bridge__srv__RosgameRegister_Response__Sequence * member =
    (rosgame_bridge__srv__RosgameRegister_Response__Sequence *)(untyped_member);
  rosgame_bridge__srv__RosgameRegister_Response__Sequence__fini(member);
  return rosgame_bridge__srv__RosgameRegister_Response__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember rosgame_bridge__srv__RosgameRegister_Event__rosidl_typesupport_introspection_c__RosgameRegister_Event_message_member_array[3] = {
  {
    "info",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rosgame_bridge__srv__RosgameRegister_Event, info),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "request",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(rosgame_bridge__srv__RosgameRegister_Event, request),  // bytes offset in struct
    NULL,  // default value
    rosgame_bridge__srv__RosgameRegister_Event__rosidl_typesupport_introspection_c__size_function__RosgameRegister_Event__request,  // size() function pointer
    rosgame_bridge__srv__RosgameRegister_Event__rosidl_typesupport_introspection_c__get_const_function__RosgameRegister_Event__request,  // get_const(index) function pointer
    rosgame_bridge__srv__RosgameRegister_Event__rosidl_typesupport_introspection_c__get_function__RosgameRegister_Event__request,  // get(index) function pointer
    rosgame_bridge__srv__RosgameRegister_Event__rosidl_typesupport_introspection_c__fetch_function__RosgameRegister_Event__request,  // fetch(index, &value) function pointer
    rosgame_bridge__srv__RosgameRegister_Event__rosidl_typesupport_introspection_c__assign_function__RosgameRegister_Event__request,  // assign(index, value) function pointer
    rosgame_bridge__srv__RosgameRegister_Event__rosidl_typesupport_introspection_c__resize_function__RosgameRegister_Event__request  // resize(index) function pointer
  },
  {
    "response",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(rosgame_bridge__srv__RosgameRegister_Event, response),  // bytes offset in struct
    NULL,  // default value
    rosgame_bridge__srv__RosgameRegister_Event__rosidl_typesupport_introspection_c__size_function__RosgameRegister_Event__response,  // size() function pointer
    rosgame_bridge__srv__RosgameRegister_Event__rosidl_typesupport_introspection_c__get_const_function__RosgameRegister_Event__response,  // get_const(index) function pointer
    rosgame_bridge__srv__RosgameRegister_Event__rosidl_typesupport_introspection_c__get_function__RosgameRegister_Event__response,  // get(index) function pointer
    rosgame_bridge__srv__RosgameRegister_Event__rosidl_typesupport_introspection_c__fetch_function__RosgameRegister_Event__response,  // fetch(index, &value) function pointer
    rosgame_bridge__srv__RosgameRegister_Event__rosidl_typesupport_introspection_c__assign_function__RosgameRegister_Event__response,  // assign(index, value) function pointer
    rosgame_bridge__srv__RosgameRegister_Event__rosidl_typesupport_introspection_c__resize_function__RosgameRegister_Event__response  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers rosgame_bridge__srv__RosgameRegister_Event__rosidl_typesupport_introspection_c__RosgameRegister_Event_message_members = {
  "rosgame_bridge__srv",  // message namespace
  "RosgameRegister_Event",  // message name
  3,  // number of fields
  sizeof(rosgame_bridge__srv__RosgameRegister_Event),
  false,  // has_any_key_member_
  rosgame_bridge__srv__RosgameRegister_Event__rosidl_typesupport_introspection_c__RosgameRegister_Event_message_member_array,  // message members
  rosgame_bridge__srv__RosgameRegister_Event__rosidl_typesupport_introspection_c__RosgameRegister_Event_init_function,  // function to initialize message memory (memory has to be allocated)
  rosgame_bridge__srv__RosgameRegister_Event__rosidl_typesupport_introspection_c__RosgameRegister_Event_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t rosgame_bridge__srv__RosgameRegister_Event__rosidl_typesupport_introspection_c__RosgameRegister_Event_message_type_support_handle = {
  0,
  &rosgame_bridge__srv__RosgameRegister_Event__rosidl_typesupport_introspection_c__RosgameRegister_Event_message_members,
  get_message_typesupport_handle_function,
  &rosgame_bridge__srv__RosgameRegister_Event__get_type_hash,
  &rosgame_bridge__srv__RosgameRegister_Event__get_type_description,
  &rosgame_bridge__srv__RosgameRegister_Event__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rosgame_bridge
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rosgame_bridge, srv, RosgameRegister_Event)() {
  rosgame_bridge__srv__RosgameRegister_Event__rosidl_typesupport_introspection_c__RosgameRegister_Event_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, service_msgs, msg, ServiceEventInfo)();
  rosgame_bridge__srv__RosgameRegister_Event__rosidl_typesupport_introspection_c__RosgameRegister_Event_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rosgame_bridge, srv, RosgameRegister_Request)();
  rosgame_bridge__srv__RosgameRegister_Event__rosidl_typesupport_introspection_c__RosgameRegister_Event_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rosgame_bridge, srv, RosgameRegister_Response)();
  if (!rosgame_bridge__srv__RosgameRegister_Event__rosidl_typesupport_introspection_c__RosgameRegister_Event_message_type_support_handle.typesupport_identifier) {
    rosgame_bridge__srv__RosgameRegister_Event__rosidl_typesupport_introspection_c__RosgameRegister_Event_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &rosgame_bridge__srv__RosgameRegister_Event__rosidl_typesupport_introspection_c__RosgameRegister_Event_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "rosgame_bridge/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosgame_bridge/srv/detail/rosgame_register__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers rosgame_bridge__srv__detail__rosgame_register__rosidl_typesupport_introspection_c__RosgameRegister_service_members = {
  "rosgame_bridge__srv",  // service namespace
  "RosgameRegister",  // service name
  // the following fields are initialized below on first access
  NULL,  // request message
  // rosgame_bridge__srv__detail__rosgame_register__rosidl_typesupport_introspection_c__RosgameRegister_Request_message_type_support_handle,
  NULL,  // response message
  // rosgame_bridge__srv__detail__rosgame_register__rosidl_typesupport_introspection_c__RosgameRegister_Response_message_type_support_handle
  NULL  // event_message
  // rosgame_bridge__srv__detail__rosgame_register__rosidl_typesupport_introspection_c__RosgameRegister_Response_message_type_support_handle
};


static rosidl_service_type_support_t rosgame_bridge__srv__detail__rosgame_register__rosidl_typesupport_introspection_c__RosgameRegister_service_type_support_handle = {
  0,
  &rosgame_bridge__srv__detail__rosgame_register__rosidl_typesupport_introspection_c__RosgameRegister_service_members,
  get_service_typesupport_handle_function,
  &rosgame_bridge__srv__RosgameRegister_Request__rosidl_typesupport_introspection_c__RosgameRegister_Request_message_type_support_handle,
  &rosgame_bridge__srv__RosgameRegister_Response__rosidl_typesupport_introspection_c__RosgameRegister_Response_message_type_support_handle,
  &rosgame_bridge__srv__RosgameRegister_Event__rosidl_typesupport_introspection_c__RosgameRegister_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    rosgame_bridge,
    srv,
    RosgameRegister
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    rosgame_bridge,
    srv,
    RosgameRegister
  ),
  &rosgame_bridge__srv__RosgameRegister__get_type_hash,
  &rosgame_bridge__srv__RosgameRegister__get_type_description,
  &rosgame_bridge__srv__RosgameRegister__get_type_description_sources,
};

// Forward declaration of message type support functions for service members
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rosgame_bridge, srv, RosgameRegister_Request)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rosgame_bridge, srv, RosgameRegister_Response)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rosgame_bridge, srv, RosgameRegister_Event)(void);

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rosgame_bridge
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rosgame_bridge, srv, RosgameRegister)(void) {
  if (!rosgame_bridge__srv__detail__rosgame_register__rosidl_typesupport_introspection_c__RosgameRegister_service_type_support_handle.typesupport_identifier) {
    rosgame_bridge__srv__detail__rosgame_register__rosidl_typesupport_introspection_c__RosgameRegister_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)rosgame_bridge__srv__detail__rosgame_register__rosidl_typesupport_introspection_c__RosgameRegister_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rosgame_bridge, srv, RosgameRegister_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rosgame_bridge, srv, RosgameRegister_Response)()->data;
  }
  if (!service_members->event_members_) {
    service_members->event_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rosgame_bridge, srv, RosgameRegister_Event)()->data;
  }

  return &rosgame_bridge__srv__detail__rosgame_register__rosidl_typesupport_introspection_c__RosgameRegister_service_type_support_handle;
}
