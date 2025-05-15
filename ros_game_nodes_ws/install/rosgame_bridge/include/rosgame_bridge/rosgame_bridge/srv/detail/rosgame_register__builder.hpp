// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rosgame_bridge:srv/RosgameRegister.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rosgame_bridge/srv/rosgame_register.hpp"


#ifndef ROSGAME_BRIDGE__SRV__DETAIL__ROSGAME_REGISTER__BUILDER_HPP_
#define ROSGAME_BRIDGE__SRV__DETAIL__ROSGAME_REGISTER__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rosgame_bridge/srv/detail/rosgame_register__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rosgame_bridge
{

namespace srv
{

namespace builder
{

class Init_RosgameRegister_Request_username
{
public:
  Init_RosgameRegister_Request_username()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::rosgame_bridge::srv::RosgameRegister_Request username(::rosgame_bridge::srv::RosgameRegister_Request::_username_type arg)
  {
    msg_.username = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rosgame_bridge::srv::RosgameRegister_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rosgame_bridge::srv::RosgameRegister_Request>()
{
  return rosgame_bridge::srv::builder::Init_RosgameRegister_Request_username();
}

}  // namespace rosgame_bridge


namespace rosgame_bridge
{

namespace srv
{

namespace builder
{

class Init_RosgameRegister_Response_robot_name
{
public:
  Init_RosgameRegister_Response_robot_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::rosgame_bridge::srv::RosgameRegister_Response robot_name(::rosgame_bridge::srv::RosgameRegister_Response::_robot_name_type arg)
  {
    msg_.robot_name = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rosgame_bridge::srv::RosgameRegister_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rosgame_bridge::srv::RosgameRegister_Response>()
{
  return rosgame_bridge::srv::builder::Init_RosgameRegister_Response_robot_name();
}

}  // namespace rosgame_bridge


namespace rosgame_bridge
{

namespace srv
{

namespace builder
{

class Init_RosgameRegister_Event_response
{
public:
  explicit Init_RosgameRegister_Event_response(::rosgame_bridge::srv::RosgameRegister_Event & msg)
  : msg_(msg)
  {}
  ::rosgame_bridge::srv::RosgameRegister_Event response(::rosgame_bridge::srv::RosgameRegister_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rosgame_bridge::srv::RosgameRegister_Event msg_;
};

class Init_RosgameRegister_Event_request
{
public:
  explicit Init_RosgameRegister_Event_request(::rosgame_bridge::srv::RosgameRegister_Event & msg)
  : msg_(msg)
  {}
  Init_RosgameRegister_Event_response request(::rosgame_bridge::srv::RosgameRegister_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_RosgameRegister_Event_response(msg_);
  }

private:
  ::rosgame_bridge::srv::RosgameRegister_Event msg_;
};

class Init_RosgameRegister_Event_info
{
public:
  Init_RosgameRegister_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RosgameRegister_Event_request info(::rosgame_bridge::srv::RosgameRegister_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_RosgameRegister_Event_request(msg_);
  }

private:
  ::rosgame_bridge::srv::RosgameRegister_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rosgame_bridge::srv::RosgameRegister_Event>()
{
  return rosgame_bridge::srv::builder::Init_RosgameRegister_Event_info();
}

}  // namespace rosgame_bridge

#endif  // ROSGAME_BRIDGE__SRV__DETAIL__ROSGAME_REGISTER__BUILDER_HPP_
