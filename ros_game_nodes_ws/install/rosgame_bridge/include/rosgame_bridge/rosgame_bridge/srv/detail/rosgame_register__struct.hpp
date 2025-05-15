// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rosgame_bridge:srv/RosgameRegister.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rosgame_bridge/srv/rosgame_register.hpp"


#ifndef ROSGAME_BRIDGE__SRV__DETAIL__ROSGAME_REGISTER__STRUCT_HPP_
#define ROSGAME_BRIDGE__SRV__DETAIL__ROSGAME_REGISTER__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__rosgame_bridge__srv__RosgameRegister_Request __attribute__((deprecated))
#else
# define DEPRECATED__rosgame_bridge__srv__RosgameRegister_Request __declspec(deprecated)
#endif

namespace rosgame_bridge
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct RosgameRegister_Request_
{
  using Type = RosgameRegister_Request_<ContainerAllocator>;

  explicit RosgameRegister_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->username = "";
    }
  }

  explicit RosgameRegister_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : username(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->username = "";
    }
  }

  // field types and members
  using _username_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _username_type username;

  // setters for named parameter idiom
  Type & set__username(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->username = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rosgame_bridge::srv::RosgameRegister_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const rosgame_bridge::srv::RosgameRegister_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rosgame_bridge::srv::RosgameRegister_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rosgame_bridge::srv::RosgameRegister_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rosgame_bridge::srv::RosgameRegister_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rosgame_bridge::srv::RosgameRegister_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rosgame_bridge::srv::RosgameRegister_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rosgame_bridge::srv::RosgameRegister_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rosgame_bridge::srv::RosgameRegister_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rosgame_bridge::srv::RosgameRegister_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rosgame_bridge__srv__RosgameRegister_Request
    std::shared_ptr<rosgame_bridge::srv::RosgameRegister_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rosgame_bridge__srv__RosgameRegister_Request
    std::shared_ptr<rosgame_bridge::srv::RosgameRegister_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RosgameRegister_Request_ & other) const
  {
    if (this->username != other.username) {
      return false;
    }
    return true;
  }
  bool operator!=(const RosgameRegister_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RosgameRegister_Request_

// alias to use template instance with default allocator
using RosgameRegister_Request =
  rosgame_bridge::srv::RosgameRegister_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace rosgame_bridge


#ifndef _WIN32
# define DEPRECATED__rosgame_bridge__srv__RosgameRegister_Response __attribute__((deprecated))
#else
# define DEPRECATED__rosgame_bridge__srv__RosgameRegister_Response __declspec(deprecated)
#endif

namespace rosgame_bridge
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct RosgameRegister_Response_
{
  using Type = RosgameRegister_Response_<ContainerAllocator>;

  explicit RosgameRegister_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->robot_name = "";
    }
  }

  explicit RosgameRegister_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : robot_name(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->robot_name = "";
    }
  }

  // field types and members
  using _robot_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _robot_name_type robot_name;

  // setters for named parameter idiom
  Type & set__robot_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->robot_name = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rosgame_bridge::srv::RosgameRegister_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const rosgame_bridge::srv::RosgameRegister_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rosgame_bridge::srv::RosgameRegister_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rosgame_bridge::srv::RosgameRegister_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rosgame_bridge::srv::RosgameRegister_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rosgame_bridge::srv::RosgameRegister_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rosgame_bridge::srv::RosgameRegister_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rosgame_bridge::srv::RosgameRegister_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rosgame_bridge::srv::RosgameRegister_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rosgame_bridge::srv::RosgameRegister_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rosgame_bridge__srv__RosgameRegister_Response
    std::shared_ptr<rosgame_bridge::srv::RosgameRegister_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rosgame_bridge__srv__RosgameRegister_Response
    std::shared_ptr<rosgame_bridge::srv::RosgameRegister_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RosgameRegister_Response_ & other) const
  {
    if (this->robot_name != other.robot_name) {
      return false;
    }
    return true;
  }
  bool operator!=(const RosgameRegister_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RosgameRegister_Response_

// alias to use template instance with default allocator
using RosgameRegister_Response =
  rosgame_bridge::srv::RosgameRegister_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace rosgame_bridge


// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__rosgame_bridge__srv__RosgameRegister_Event __attribute__((deprecated))
#else
# define DEPRECATED__rosgame_bridge__srv__RosgameRegister_Event __declspec(deprecated)
#endif

namespace rosgame_bridge
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct RosgameRegister_Event_
{
  using Type = RosgameRegister_Event_<ContainerAllocator>;

  explicit RosgameRegister_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit RosgameRegister_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<rosgame_bridge::srv::RosgameRegister_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<rosgame_bridge::srv::RosgameRegister_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<rosgame_bridge::srv::RosgameRegister_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<rosgame_bridge::srv::RosgameRegister_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<rosgame_bridge::srv::RosgameRegister_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<rosgame_bridge::srv::RosgameRegister_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<rosgame_bridge::srv::RosgameRegister_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<rosgame_bridge::srv::RosgameRegister_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rosgame_bridge::srv::RosgameRegister_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const rosgame_bridge::srv::RosgameRegister_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rosgame_bridge::srv::RosgameRegister_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rosgame_bridge::srv::RosgameRegister_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rosgame_bridge::srv::RosgameRegister_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rosgame_bridge::srv::RosgameRegister_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rosgame_bridge::srv::RosgameRegister_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rosgame_bridge::srv::RosgameRegister_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rosgame_bridge::srv::RosgameRegister_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rosgame_bridge::srv::RosgameRegister_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rosgame_bridge__srv__RosgameRegister_Event
    std::shared_ptr<rosgame_bridge::srv::RosgameRegister_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rosgame_bridge__srv__RosgameRegister_Event
    std::shared_ptr<rosgame_bridge::srv::RosgameRegister_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RosgameRegister_Event_ & other) const
  {
    if (this->info != other.info) {
      return false;
    }
    if (this->request != other.request) {
      return false;
    }
    if (this->response != other.response) {
      return false;
    }
    return true;
  }
  bool operator!=(const RosgameRegister_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RosgameRegister_Event_

// alias to use template instance with default allocator
using RosgameRegister_Event =
  rosgame_bridge::srv::RosgameRegister_Event_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace rosgame_bridge

namespace rosgame_bridge
{

namespace srv
{

struct RosgameRegister
{
  using Request = rosgame_bridge::srv::RosgameRegister_Request;
  using Response = rosgame_bridge::srv::RosgameRegister_Response;
  using Event = rosgame_bridge::srv::RosgameRegister_Event;
};

}  // namespace srv

}  // namespace rosgame_bridge

#endif  // ROSGAME_BRIDGE__SRV__DETAIL__ROSGAME_REGISTER__STRUCT_HPP_
