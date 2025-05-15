// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rosgame_bridge:srv/RosgameRegister.idl
// generated code does not contain a copyright notice
#include "rosgame_bridge/srv/detail/rosgame_register__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `username`
#include "rosidl_runtime_c/string_functions.h"

bool
rosgame_bridge__srv__RosgameRegister_Request__init(rosgame_bridge__srv__RosgameRegister_Request * msg)
{
  if (!msg) {
    return false;
  }
  // username
  if (!rosidl_runtime_c__String__init(&msg->username)) {
    rosgame_bridge__srv__RosgameRegister_Request__fini(msg);
    return false;
  }
  return true;
}

void
rosgame_bridge__srv__RosgameRegister_Request__fini(rosgame_bridge__srv__RosgameRegister_Request * msg)
{
  if (!msg) {
    return;
  }
  // username
  rosidl_runtime_c__String__fini(&msg->username);
}

bool
rosgame_bridge__srv__RosgameRegister_Request__are_equal(const rosgame_bridge__srv__RosgameRegister_Request * lhs, const rosgame_bridge__srv__RosgameRegister_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // username
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->username), &(rhs->username)))
  {
    return false;
  }
  return true;
}

bool
rosgame_bridge__srv__RosgameRegister_Request__copy(
  const rosgame_bridge__srv__RosgameRegister_Request * input,
  rosgame_bridge__srv__RosgameRegister_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // username
  if (!rosidl_runtime_c__String__copy(
      &(input->username), &(output->username)))
  {
    return false;
  }
  return true;
}

rosgame_bridge__srv__RosgameRegister_Request *
rosgame_bridge__srv__RosgameRegister_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rosgame_bridge__srv__RosgameRegister_Request * msg = (rosgame_bridge__srv__RosgameRegister_Request *)allocator.allocate(sizeof(rosgame_bridge__srv__RosgameRegister_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rosgame_bridge__srv__RosgameRegister_Request));
  bool success = rosgame_bridge__srv__RosgameRegister_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rosgame_bridge__srv__RosgameRegister_Request__destroy(rosgame_bridge__srv__RosgameRegister_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rosgame_bridge__srv__RosgameRegister_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rosgame_bridge__srv__RosgameRegister_Request__Sequence__init(rosgame_bridge__srv__RosgameRegister_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rosgame_bridge__srv__RosgameRegister_Request * data = NULL;

  if (size) {
    data = (rosgame_bridge__srv__RosgameRegister_Request *)allocator.zero_allocate(size, sizeof(rosgame_bridge__srv__RosgameRegister_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rosgame_bridge__srv__RosgameRegister_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rosgame_bridge__srv__RosgameRegister_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
rosgame_bridge__srv__RosgameRegister_Request__Sequence__fini(rosgame_bridge__srv__RosgameRegister_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      rosgame_bridge__srv__RosgameRegister_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

rosgame_bridge__srv__RosgameRegister_Request__Sequence *
rosgame_bridge__srv__RosgameRegister_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rosgame_bridge__srv__RosgameRegister_Request__Sequence * array = (rosgame_bridge__srv__RosgameRegister_Request__Sequence *)allocator.allocate(sizeof(rosgame_bridge__srv__RosgameRegister_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rosgame_bridge__srv__RosgameRegister_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rosgame_bridge__srv__RosgameRegister_Request__Sequence__destroy(rosgame_bridge__srv__RosgameRegister_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rosgame_bridge__srv__RosgameRegister_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rosgame_bridge__srv__RosgameRegister_Request__Sequence__are_equal(const rosgame_bridge__srv__RosgameRegister_Request__Sequence * lhs, const rosgame_bridge__srv__RosgameRegister_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rosgame_bridge__srv__RosgameRegister_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rosgame_bridge__srv__RosgameRegister_Request__Sequence__copy(
  const rosgame_bridge__srv__RosgameRegister_Request__Sequence * input,
  rosgame_bridge__srv__RosgameRegister_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rosgame_bridge__srv__RosgameRegister_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rosgame_bridge__srv__RosgameRegister_Request * data =
      (rosgame_bridge__srv__RosgameRegister_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rosgame_bridge__srv__RosgameRegister_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rosgame_bridge__srv__RosgameRegister_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rosgame_bridge__srv__RosgameRegister_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `robot_name`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

bool
rosgame_bridge__srv__RosgameRegister_Response__init(rosgame_bridge__srv__RosgameRegister_Response * msg)
{
  if (!msg) {
    return false;
  }
  // robot_name
  if (!rosidl_runtime_c__String__init(&msg->robot_name)) {
    rosgame_bridge__srv__RosgameRegister_Response__fini(msg);
    return false;
  }
  return true;
}

void
rosgame_bridge__srv__RosgameRegister_Response__fini(rosgame_bridge__srv__RosgameRegister_Response * msg)
{
  if (!msg) {
    return;
  }
  // robot_name
  rosidl_runtime_c__String__fini(&msg->robot_name);
}

bool
rosgame_bridge__srv__RosgameRegister_Response__are_equal(const rosgame_bridge__srv__RosgameRegister_Response * lhs, const rosgame_bridge__srv__RosgameRegister_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // robot_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->robot_name), &(rhs->robot_name)))
  {
    return false;
  }
  return true;
}

bool
rosgame_bridge__srv__RosgameRegister_Response__copy(
  const rosgame_bridge__srv__RosgameRegister_Response * input,
  rosgame_bridge__srv__RosgameRegister_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // robot_name
  if (!rosidl_runtime_c__String__copy(
      &(input->robot_name), &(output->robot_name)))
  {
    return false;
  }
  return true;
}

rosgame_bridge__srv__RosgameRegister_Response *
rosgame_bridge__srv__RosgameRegister_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rosgame_bridge__srv__RosgameRegister_Response * msg = (rosgame_bridge__srv__RosgameRegister_Response *)allocator.allocate(sizeof(rosgame_bridge__srv__RosgameRegister_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rosgame_bridge__srv__RosgameRegister_Response));
  bool success = rosgame_bridge__srv__RosgameRegister_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rosgame_bridge__srv__RosgameRegister_Response__destroy(rosgame_bridge__srv__RosgameRegister_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rosgame_bridge__srv__RosgameRegister_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rosgame_bridge__srv__RosgameRegister_Response__Sequence__init(rosgame_bridge__srv__RosgameRegister_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rosgame_bridge__srv__RosgameRegister_Response * data = NULL;

  if (size) {
    data = (rosgame_bridge__srv__RosgameRegister_Response *)allocator.zero_allocate(size, sizeof(rosgame_bridge__srv__RosgameRegister_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rosgame_bridge__srv__RosgameRegister_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rosgame_bridge__srv__RosgameRegister_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
rosgame_bridge__srv__RosgameRegister_Response__Sequence__fini(rosgame_bridge__srv__RosgameRegister_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      rosgame_bridge__srv__RosgameRegister_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

rosgame_bridge__srv__RosgameRegister_Response__Sequence *
rosgame_bridge__srv__RosgameRegister_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rosgame_bridge__srv__RosgameRegister_Response__Sequence * array = (rosgame_bridge__srv__RosgameRegister_Response__Sequence *)allocator.allocate(sizeof(rosgame_bridge__srv__RosgameRegister_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rosgame_bridge__srv__RosgameRegister_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rosgame_bridge__srv__RosgameRegister_Response__Sequence__destroy(rosgame_bridge__srv__RosgameRegister_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rosgame_bridge__srv__RosgameRegister_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rosgame_bridge__srv__RosgameRegister_Response__Sequence__are_equal(const rosgame_bridge__srv__RosgameRegister_Response__Sequence * lhs, const rosgame_bridge__srv__RosgameRegister_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rosgame_bridge__srv__RosgameRegister_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rosgame_bridge__srv__RosgameRegister_Response__Sequence__copy(
  const rosgame_bridge__srv__RosgameRegister_Response__Sequence * input,
  rosgame_bridge__srv__RosgameRegister_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rosgame_bridge__srv__RosgameRegister_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rosgame_bridge__srv__RosgameRegister_Response * data =
      (rosgame_bridge__srv__RosgameRegister_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rosgame_bridge__srv__RosgameRegister_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rosgame_bridge__srv__RosgameRegister_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rosgame_bridge__srv__RosgameRegister_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `info`
#include "service_msgs/msg/detail/service_event_info__functions.h"
// Member `request`
// Member `response`
// already included above
// #include "rosgame_bridge/srv/detail/rosgame_register__functions.h"

bool
rosgame_bridge__srv__RosgameRegister_Event__init(rosgame_bridge__srv__RosgameRegister_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    rosgame_bridge__srv__RosgameRegister_Event__fini(msg);
    return false;
  }
  // request
  if (!rosgame_bridge__srv__RosgameRegister_Request__Sequence__init(&msg->request, 0)) {
    rosgame_bridge__srv__RosgameRegister_Event__fini(msg);
    return false;
  }
  // response
  if (!rosgame_bridge__srv__RosgameRegister_Response__Sequence__init(&msg->response, 0)) {
    rosgame_bridge__srv__RosgameRegister_Event__fini(msg);
    return false;
  }
  return true;
}

void
rosgame_bridge__srv__RosgameRegister_Event__fini(rosgame_bridge__srv__RosgameRegister_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  rosgame_bridge__srv__RosgameRegister_Request__Sequence__fini(&msg->request);
  // response
  rosgame_bridge__srv__RosgameRegister_Response__Sequence__fini(&msg->response);
}

bool
rosgame_bridge__srv__RosgameRegister_Event__are_equal(const rosgame_bridge__srv__RosgameRegister_Event * lhs, const rosgame_bridge__srv__RosgameRegister_Event * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__are_equal(
      &(lhs->info), &(rhs->info)))
  {
    return false;
  }
  // request
  if (!rosgame_bridge__srv__RosgameRegister_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!rosgame_bridge__srv__RosgameRegister_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
rosgame_bridge__srv__RosgameRegister_Event__copy(
  const rosgame_bridge__srv__RosgameRegister_Event * input,
  rosgame_bridge__srv__RosgameRegister_Event * output)
{
  if (!input || !output) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__copy(
      &(input->info), &(output->info)))
  {
    return false;
  }
  // request
  if (!rosgame_bridge__srv__RosgameRegister_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!rosgame_bridge__srv__RosgameRegister_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

rosgame_bridge__srv__RosgameRegister_Event *
rosgame_bridge__srv__RosgameRegister_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rosgame_bridge__srv__RosgameRegister_Event * msg = (rosgame_bridge__srv__RosgameRegister_Event *)allocator.allocate(sizeof(rosgame_bridge__srv__RosgameRegister_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rosgame_bridge__srv__RosgameRegister_Event));
  bool success = rosgame_bridge__srv__RosgameRegister_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rosgame_bridge__srv__RosgameRegister_Event__destroy(rosgame_bridge__srv__RosgameRegister_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rosgame_bridge__srv__RosgameRegister_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rosgame_bridge__srv__RosgameRegister_Event__Sequence__init(rosgame_bridge__srv__RosgameRegister_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rosgame_bridge__srv__RosgameRegister_Event * data = NULL;

  if (size) {
    data = (rosgame_bridge__srv__RosgameRegister_Event *)allocator.zero_allocate(size, sizeof(rosgame_bridge__srv__RosgameRegister_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rosgame_bridge__srv__RosgameRegister_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rosgame_bridge__srv__RosgameRegister_Event__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
rosgame_bridge__srv__RosgameRegister_Event__Sequence__fini(rosgame_bridge__srv__RosgameRegister_Event__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      rosgame_bridge__srv__RosgameRegister_Event__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

rosgame_bridge__srv__RosgameRegister_Event__Sequence *
rosgame_bridge__srv__RosgameRegister_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rosgame_bridge__srv__RosgameRegister_Event__Sequence * array = (rosgame_bridge__srv__RosgameRegister_Event__Sequence *)allocator.allocate(sizeof(rosgame_bridge__srv__RosgameRegister_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rosgame_bridge__srv__RosgameRegister_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rosgame_bridge__srv__RosgameRegister_Event__Sequence__destroy(rosgame_bridge__srv__RosgameRegister_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rosgame_bridge__srv__RosgameRegister_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rosgame_bridge__srv__RosgameRegister_Event__Sequence__are_equal(const rosgame_bridge__srv__RosgameRegister_Event__Sequence * lhs, const rosgame_bridge__srv__RosgameRegister_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rosgame_bridge__srv__RosgameRegister_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rosgame_bridge__srv__RosgameRegister_Event__Sequence__copy(
  const rosgame_bridge__srv__RosgameRegister_Event__Sequence * input,
  rosgame_bridge__srv__RosgameRegister_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rosgame_bridge__srv__RosgameRegister_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rosgame_bridge__srv__RosgameRegister_Event * data =
      (rosgame_bridge__srv__RosgameRegister_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rosgame_bridge__srv__RosgameRegister_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rosgame_bridge__srv__RosgameRegister_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rosgame_bridge__srv__RosgameRegister_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
