// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from rosgame_bridge:srv/RosgameRegister.idl
// generated code does not contain a copyright notice

#include "rosgame_bridge/srv/detail/rosgame_register__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_rosgame_bridge
const rosidl_type_hash_t *
rosgame_bridge__srv__RosgameRegister__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x8d, 0xea, 0xb9, 0x7f, 0x8c, 0x75, 0x28, 0xaf,
      0x7c, 0x11, 0xe4, 0x65, 0x97, 0xfe, 0x14, 0x25,
      0x36, 0xc7, 0xf5, 0xc2, 0x4c, 0x4f, 0xcf, 0x55,
      0x98, 0x25, 0xe7, 0x59, 0xb0, 0x55, 0xdb, 0x81,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_rosgame_bridge
const rosidl_type_hash_t *
rosgame_bridge__srv__RosgameRegister_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xe2, 0x62, 0x5d, 0x14, 0x01, 0x7f, 0x0e, 0x36,
      0x25, 0x1c, 0x8d, 0x27, 0x9f, 0x23, 0x2b, 0xc7,
      0x02, 0x05, 0x91, 0x59, 0xd9, 0x91, 0xa1, 0x69,
      0xea, 0xb9, 0xbc, 0xdc, 0xc2, 0x11, 0xb8, 0x95,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_rosgame_bridge
const rosidl_type_hash_t *
rosgame_bridge__srv__RosgameRegister_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xe6, 0x18, 0x4a, 0x79, 0xf4, 0x81, 0x0f, 0xaa,
      0x31, 0x2e, 0x84, 0x27, 0x32, 0x40, 0x61, 0x4b,
      0x7f, 0xaf, 0x94, 0xb9, 0xc8, 0x9f, 0xa6, 0x2d,
      0x25, 0xfa, 0xfb, 0x60, 0x3f, 0x16, 0x5d, 0xa9,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_rosgame_bridge
const rosidl_type_hash_t *
rosgame_bridge__srv__RosgameRegister_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xd6, 0x53, 0xe5, 0x30, 0x26, 0xac, 0x46, 0x57,
      0x61, 0xbd, 0x47, 0x64, 0xbb, 0x73, 0xde, 0x3b,
      0xed, 0x4e, 0x25, 0x62, 0x84, 0xdd, 0x4e, 0x4e,
      0x77, 0x8a, 0x79, 0x37, 0xe7, 0x17, 0x32, 0x8a,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "builtin_interfaces/msg/detail/time__functions.h"
#include "service_msgs/msg/detail/service_event_info__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t service_msgs__msg__ServiceEventInfo__EXPECTED_HASH = {1, {
    0x41, 0xbc, 0xbb, 0xe0, 0x7a, 0x75, 0xc9, 0xb5,
    0x2b, 0xc9, 0x6b, 0xfd, 0x5c, 0x24, 0xd7, 0xf0,
    0xfc, 0x0a, 0x08, 0xc0, 0xcb, 0x79, 0x21, 0xb3,
    0x37, 0x3c, 0x57, 0x32, 0x34, 0x5a, 0x6f, 0x45,
  }};
#endif

static char rosgame_bridge__srv__RosgameRegister__TYPE_NAME[] = "rosgame_bridge/srv/RosgameRegister";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char rosgame_bridge__srv__RosgameRegister_Event__TYPE_NAME[] = "rosgame_bridge/srv/RosgameRegister_Event";
static char rosgame_bridge__srv__RosgameRegister_Request__TYPE_NAME[] = "rosgame_bridge/srv/RosgameRegister_Request";
static char rosgame_bridge__srv__RosgameRegister_Response__TYPE_NAME[] = "rosgame_bridge/srv/RosgameRegister_Response";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";

// Define type names, field names, and default values
static char rosgame_bridge__srv__RosgameRegister__FIELD_NAME__request_message[] = "request_message";
static char rosgame_bridge__srv__RosgameRegister__FIELD_NAME__response_message[] = "response_message";
static char rosgame_bridge__srv__RosgameRegister__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field rosgame_bridge__srv__RosgameRegister__FIELDS[] = {
  {
    {rosgame_bridge__srv__RosgameRegister__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {rosgame_bridge__srv__RosgameRegister_Request__TYPE_NAME, 42, 42},
    },
    {NULL, 0, 0},
  },
  {
    {rosgame_bridge__srv__RosgameRegister__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {rosgame_bridge__srv__RosgameRegister_Response__TYPE_NAME, 43, 43},
    },
    {NULL, 0, 0},
  },
  {
    {rosgame_bridge__srv__RosgameRegister__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {rosgame_bridge__srv__RosgameRegister_Event__TYPE_NAME, 40, 40},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription rosgame_bridge__srv__RosgameRegister__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {rosgame_bridge__srv__RosgameRegister_Event__TYPE_NAME, 40, 40},
    {NULL, 0, 0},
  },
  {
    {rosgame_bridge__srv__RosgameRegister_Request__TYPE_NAME, 42, 42},
    {NULL, 0, 0},
  },
  {
    {rosgame_bridge__srv__RosgameRegister_Response__TYPE_NAME, 43, 43},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
rosgame_bridge__srv__RosgameRegister__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {rosgame_bridge__srv__RosgameRegister__TYPE_NAME, 34, 34},
      {rosgame_bridge__srv__RosgameRegister__FIELDS, 3, 3},
    },
    {rosgame_bridge__srv__RosgameRegister__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = rosgame_bridge__srv__RosgameRegister_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = rosgame_bridge__srv__RosgameRegister_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = rosgame_bridge__srv__RosgameRegister_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char rosgame_bridge__srv__RosgameRegister_Request__FIELD_NAME__username[] = "username";

static rosidl_runtime_c__type_description__Field rosgame_bridge__srv__RosgameRegister_Request__FIELDS[] = {
  {
    {rosgame_bridge__srv__RosgameRegister_Request__FIELD_NAME__username, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
rosgame_bridge__srv__RosgameRegister_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {rosgame_bridge__srv__RosgameRegister_Request__TYPE_NAME, 42, 42},
      {rosgame_bridge__srv__RosgameRegister_Request__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char rosgame_bridge__srv__RosgameRegister_Response__FIELD_NAME__robot_name[] = "robot_name";

static rosidl_runtime_c__type_description__Field rosgame_bridge__srv__RosgameRegister_Response__FIELDS[] = {
  {
    {rosgame_bridge__srv__RosgameRegister_Response__FIELD_NAME__robot_name, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
rosgame_bridge__srv__RosgameRegister_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {rosgame_bridge__srv__RosgameRegister_Response__TYPE_NAME, 43, 43},
      {rosgame_bridge__srv__RosgameRegister_Response__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char rosgame_bridge__srv__RosgameRegister_Event__FIELD_NAME__info[] = "info";
static char rosgame_bridge__srv__RosgameRegister_Event__FIELD_NAME__request[] = "request";
static char rosgame_bridge__srv__RosgameRegister_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field rosgame_bridge__srv__RosgameRegister_Event__FIELDS[] = {
  {
    {rosgame_bridge__srv__RosgameRegister_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {rosgame_bridge__srv__RosgameRegister_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {rosgame_bridge__srv__RosgameRegister_Request__TYPE_NAME, 42, 42},
    },
    {NULL, 0, 0},
  },
  {
    {rosgame_bridge__srv__RosgameRegister_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {rosgame_bridge__srv__RosgameRegister_Response__TYPE_NAME, 43, 43},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription rosgame_bridge__srv__RosgameRegister_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {rosgame_bridge__srv__RosgameRegister_Request__TYPE_NAME, 42, 42},
    {NULL, 0, 0},
  },
  {
    {rosgame_bridge__srv__RosgameRegister_Response__TYPE_NAME, 43, 43},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
rosgame_bridge__srv__RosgameRegister_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {rosgame_bridge__srv__RosgameRegister_Event__TYPE_NAME, 40, 40},
      {rosgame_bridge__srv__RosgameRegister_Event__FIELDS, 3, 3},
    },
    {rosgame_bridge__srv__RosgameRegister_Event__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = rosgame_bridge__srv__RosgameRegister_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = rosgame_bridge__srv__RosgameRegister_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "string username\n"
  "---\n"
  "string robot_name";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
rosgame_bridge__srv__RosgameRegister__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {rosgame_bridge__srv__RosgameRegister__TYPE_NAME, 34, 34},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 37, 37},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
rosgame_bridge__srv__RosgameRegister_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {rosgame_bridge__srv__RosgameRegister_Request__TYPE_NAME, 42, 42},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
rosgame_bridge__srv__RosgameRegister_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {rosgame_bridge__srv__RosgameRegister_Response__TYPE_NAME, 43, 43},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
rosgame_bridge__srv__RosgameRegister_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {rosgame_bridge__srv__RosgameRegister_Event__TYPE_NAME, 40, 40},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
rosgame_bridge__srv__RosgameRegister__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *rosgame_bridge__srv__RosgameRegister__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *rosgame_bridge__srv__RosgameRegister_Event__get_individual_type_description_source(NULL);
    sources[3] = *rosgame_bridge__srv__RosgameRegister_Request__get_individual_type_description_source(NULL);
    sources[4] = *rosgame_bridge__srv__RosgameRegister_Response__get_individual_type_description_source(NULL);
    sources[5] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
rosgame_bridge__srv__RosgameRegister_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *rosgame_bridge__srv__RosgameRegister_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
rosgame_bridge__srv__RosgameRegister_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *rosgame_bridge__srv__RosgameRegister_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
rosgame_bridge__srv__RosgameRegister_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *rosgame_bridge__srv__RosgameRegister_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *rosgame_bridge__srv__RosgameRegister_Request__get_individual_type_description_source(NULL);
    sources[3] = *rosgame_bridge__srv__RosgameRegister_Response__get_individual_type_description_source(NULL);
    sources[4] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
