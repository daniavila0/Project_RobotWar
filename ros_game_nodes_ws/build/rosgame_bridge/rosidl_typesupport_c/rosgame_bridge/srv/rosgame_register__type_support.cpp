// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from rosgame_bridge:srv/RosgameRegister.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosgame_bridge/srv/detail/rosgame_register__struct.h"
#include "rosgame_bridge/srv/detail/rosgame_register__type_support.h"
#include "rosgame_bridge/srv/detail/rosgame_register__functions.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace rosgame_bridge
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _RosgameRegister_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _RosgameRegister_Request_type_support_ids_t;

static const _RosgameRegister_Request_type_support_ids_t _RosgameRegister_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _RosgameRegister_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _RosgameRegister_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _RosgameRegister_Request_type_support_symbol_names_t _RosgameRegister_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, rosgame_bridge, srv, RosgameRegister_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rosgame_bridge, srv, RosgameRegister_Request)),
  }
};

typedef struct _RosgameRegister_Request_type_support_data_t
{
  void * data[2];
} _RosgameRegister_Request_type_support_data_t;

static _RosgameRegister_Request_type_support_data_t _RosgameRegister_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _RosgameRegister_Request_message_typesupport_map = {
  2,
  "rosgame_bridge",
  &_RosgameRegister_Request_message_typesupport_ids.typesupport_identifier[0],
  &_RosgameRegister_Request_message_typesupport_symbol_names.symbol_name[0],
  &_RosgameRegister_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t RosgameRegister_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_RosgameRegister_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &rosgame_bridge__srv__RosgameRegister_Request__get_type_hash,
  &rosgame_bridge__srv__RosgameRegister_Request__get_type_description,
  &rosgame_bridge__srv__RosgameRegister_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace rosgame_bridge

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, rosgame_bridge, srv, RosgameRegister_Request)() {
  return &::rosgame_bridge::srv::rosidl_typesupport_c::RosgameRegister_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosgame_bridge/srv/detail/rosgame_register__struct.h"
// already included above
// #include "rosgame_bridge/srv/detail/rosgame_register__type_support.h"
// already included above
// #include "rosgame_bridge/srv/detail/rosgame_register__functions.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace rosgame_bridge
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _RosgameRegister_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _RosgameRegister_Response_type_support_ids_t;

static const _RosgameRegister_Response_type_support_ids_t _RosgameRegister_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _RosgameRegister_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _RosgameRegister_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _RosgameRegister_Response_type_support_symbol_names_t _RosgameRegister_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, rosgame_bridge, srv, RosgameRegister_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rosgame_bridge, srv, RosgameRegister_Response)),
  }
};

typedef struct _RosgameRegister_Response_type_support_data_t
{
  void * data[2];
} _RosgameRegister_Response_type_support_data_t;

static _RosgameRegister_Response_type_support_data_t _RosgameRegister_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _RosgameRegister_Response_message_typesupport_map = {
  2,
  "rosgame_bridge",
  &_RosgameRegister_Response_message_typesupport_ids.typesupport_identifier[0],
  &_RosgameRegister_Response_message_typesupport_symbol_names.symbol_name[0],
  &_RosgameRegister_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t RosgameRegister_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_RosgameRegister_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &rosgame_bridge__srv__RosgameRegister_Response__get_type_hash,
  &rosgame_bridge__srv__RosgameRegister_Response__get_type_description,
  &rosgame_bridge__srv__RosgameRegister_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace rosgame_bridge

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, rosgame_bridge, srv, RosgameRegister_Response)() {
  return &::rosgame_bridge::srv::rosidl_typesupport_c::RosgameRegister_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosgame_bridge/srv/detail/rosgame_register__struct.h"
// already included above
// #include "rosgame_bridge/srv/detail/rosgame_register__type_support.h"
// already included above
// #include "rosgame_bridge/srv/detail/rosgame_register__functions.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace rosgame_bridge
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _RosgameRegister_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _RosgameRegister_Event_type_support_ids_t;

static const _RosgameRegister_Event_type_support_ids_t _RosgameRegister_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _RosgameRegister_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _RosgameRegister_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _RosgameRegister_Event_type_support_symbol_names_t _RosgameRegister_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, rosgame_bridge, srv, RosgameRegister_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rosgame_bridge, srv, RosgameRegister_Event)),
  }
};

typedef struct _RosgameRegister_Event_type_support_data_t
{
  void * data[2];
} _RosgameRegister_Event_type_support_data_t;

static _RosgameRegister_Event_type_support_data_t _RosgameRegister_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _RosgameRegister_Event_message_typesupport_map = {
  2,
  "rosgame_bridge",
  &_RosgameRegister_Event_message_typesupport_ids.typesupport_identifier[0],
  &_RosgameRegister_Event_message_typesupport_symbol_names.symbol_name[0],
  &_RosgameRegister_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t RosgameRegister_Event_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_RosgameRegister_Event_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &rosgame_bridge__srv__RosgameRegister_Event__get_type_hash,
  &rosgame_bridge__srv__RosgameRegister_Event__get_type_description,
  &rosgame_bridge__srv__RosgameRegister_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace rosgame_bridge

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, rosgame_bridge, srv, RosgameRegister_Event)() {
  return &::rosgame_bridge::srv::rosidl_typesupport_c::RosgameRegister_Event_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "rosgame_bridge/srv/detail/rosgame_register__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
#include "service_msgs/msg/service_event_info.h"
#include "builtin_interfaces/msg/time.h"

namespace rosgame_bridge
{

namespace srv
{

namespace rosidl_typesupport_c
{
typedef struct _RosgameRegister_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _RosgameRegister_type_support_ids_t;

static const _RosgameRegister_type_support_ids_t _RosgameRegister_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _RosgameRegister_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _RosgameRegister_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _RosgameRegister_type_support_symbol_names_t _RosgameRegister_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, rosgame_bridge, srv, RosgameRegister)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rosgame_bridge, srv, RosgameRegister)),
  }
};

typedef struct _RosgameRegister_type_support_data_t
{
  void * data[2];
} _RosgameRegister_type_support_data_t;

static _RosgameRegister_type_support_data_t _RosgameRegister_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _RosgameRegister_service_typesupport_map = {
  2,
  "rosgame_bridge",
  &_RosgameRegister_service_typesupport_ids.typesupport_identifier[0],
  &_RosgameRegister_service_typesupport_symbol_names.symbol_name[0],
  &_RosgameRegister_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t RosgameRegister_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_RosgameRegister_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
  &RosgameRegister_Request_message_type_support_handle,
  &RosgameRegister_Response_message_type_support_handle,
  &RosgameRegister_Event_message_type_support_handle,
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

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace rosgame_bridge

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, rosgame_bridge, srv, RosgameRegister)() {
  return &::rosgame_bridge::srv::rosidl_typesupport_c::RosgameRegister_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif
