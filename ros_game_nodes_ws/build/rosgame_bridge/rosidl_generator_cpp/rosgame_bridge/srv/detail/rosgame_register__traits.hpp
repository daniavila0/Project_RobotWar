// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rosgame_bridge:srv/RosgameRegister.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rosgame_bridge/srv/rosgame_register.hpp"


#ifndef ROSGAME_BRIDGE__SRV__DETAIL__ROSGAME_REGISTER__TRAITS_HPP_
#define ROSGAME_BRIDGE__SRV__DETAIL__ROSGAME_REGISTER__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "rosgame_bridge/srv/detail/rosgame_register__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace rosgame_bridge
{

namespace srv
{

inline void to_flow_style_yaml(
  const RosgameRegister_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: username
  {
    out << "username: ";
    rosidl_generator_traits::value_to_yaml(msg.username, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RosgameRegister_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: username
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "username: ";
    rosidl_generator_traits::value_to_yaml(msg.username, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RosgameRegister_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace rosgame_bridge

namespace rosidl_generator_traits
{

[[deprecated("use rosgame_bridge::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const rosgame_bridge::srv::RosgameRegister_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  rosgame_bridge::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rosgame_bridge::srv::to_yaml() instead")]]
inline std::string to_yaml(const rosgame_bridge::srv::RosgameRegister_Request & msg)
{
  return rosgame_bridge::srv::to_yaml(msg);
}

template<>
inline const char * data_type<rosgame_bridge::srv::RosgameRegister_Request>()
{
  return "rosgame_bridge::srv::RosgameRegister_Request";
}

template<>
inline const char * name<rosgame_bridge::srv::RosgameRegister_Request>()
{
  return "rosgame_bridge/srv/RosgameRegister_Request";
}

template<>
struct has_fixed_size<rosgame_bridge::srv::RosgameRegister_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<rosgame_bridge::srv::RosgameRegister_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<rosgame_bridge::srv::RosgameRegister_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosgame_bridge
{

namespace srv
{

inline void to_flow_style_yaml(
  const RosgameRegister_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: robot_name
  {
    out << "robot_name: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_name, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RosgameRegister_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: robot_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "robot_name: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_name, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RosgameRegister_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace rosgame_bridge

namespace rosidl_generator_traits
{

[[deprecated("use rosgame_bridge::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const rosgame_bridge::srv::RosgameRegister_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  rosgame_bridge::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rosgame_bridge::srv::to_yaml() instead")]]
inline std::string to_yaml(const rosgame_bridge::srv::RosgameRegister_Response & msg)
{
  return rosgame_bridge::srv::to_yaml(msg);
}

template<>
inline const char * data_type<rosgame_bridge::srv::RosgameRegister_Response>()
{
  return "rosgame_bridge::srv::RosgameRegister_Response";
}

template<>
inline const char * name<rosgame_bridge::srv::RosgameRegister_Response>()
{
  return "rosgame_bridge/srv/RosgameRegister_Response";
}

template<>
struct has_fixed_size<rosgame_bridge::srv::RosgameRegister_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<rosgame_bridge::srv::RosgameRegister_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<rosgame_bridge::srv::RosgameRegister_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace rosgame_bridge
{

namespace srv
{

inline void to_flow_style_yaml(
  const RosgameRegister_Event & msg,
  std::ostream & out)
{
  out << "{";
  // member: info
  {
    out << "info: ";
    to_flow_style_yaml(msg.info, out);
    out << ", ";
  }

  // member: request
  {
    if (msg.request.size() == 0) {
      out << "request: []";
    } else {
      out << "request: [";
      size_t pending_items = msg.request.size();
      for (auto item : msg.request) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: response
  {
    if (msg.response.size() == 0) {
      out << "response: []";
    } else {
      out << "response: [";
      size_t pending_items = msg.response.size();
      for (auto item : msg.response) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RosgameRegister_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "info:\n";
    to_block_style_yaml(msg.info, out, indentation + 2);
  }

  // member: request
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.request.size() == 0) {
      out << "request: []\n";
    } else {
      out << "request:\n";
      for (auto item : msg.request) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.response.size() == 0) {
      out << "response: []\n";
    } else {
      out << "response:\n";
      for (auto item : msg.response) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RosgameRegister_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace rosgame_bridge

namespace rosidl_generator_traits
{

[[deprecated("use rosgame_bridge::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const rosgame_bridge::srv::RosgameRegister_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  rosgame_bridge::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rosgame_bridge::srv::to_yaml() instead")]]
inline std::string to_yaml(const rosgame_bridge::srv::RosgameRegister_Event & msg)
{
  return rosgame_bridge::srv::to_yaml(msg);
}

template<>
inline const char * data_type<rosgame_bridge::srv::RosgameRegister_Event>()
{
  return "rosgame_bridge::srv::RosgameRegister_Event";
}

template<>
inline const char * name<rosgame_bridge::srv::RosgameRegister_Event>()
{
  return "rosgame_bridge/srv/RosgameRegister_Event";
}

template<>
struct has_fixed_size<rosgame_bridge::srv::RosgameRegister_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<rosgame_bridge::srv::RosgameRegister_Event>
  : std::integral_constant<bool, has_bounded_size<rosgame_bridge::srv::RosgameRegister_Request>::value && has_bounded_size<rosgame_bridge::srv::RosgameRegister_Response>::value && has_bounded_size<service_msgs::msg::ServiceEventInfo>::value> {};

template<>
struct is_message<rosgame_bridge::srv::RosgameRegister_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<rosgame_bridge::srv::RosgameRegister>()
{
  return "rosgame_bridge::srv::RosgameRegister";
}

template<>
inline const char * name<rosgame_bridge::srv::RosgameRegister>()
{
  return "rosgame_bridge/srv/RosgameRegister";
}

template<>
struct has_fixed_size<rosgame_bridge::srv::RosgameRegister>
  : std::integral_constant<
    bool,
    has_fixed_size<rosgame_bridge::srv::RosgameRegister_Request>::value &&
    has_fixed_size<rosgame_bridge::srv::RosgameRegister_Response>::value
  >
{
};

template<>
struct has_bounded_size<rosgame_bridge::srv::RosgameRegister>
  : std::integral_constant<
    bool,
    has_bounded_size<rosgame_bridge::srv::RosgameRegister_Request>::value &&
    has_bounded_size<rosgame_bridge::srv::RosgameRegister_Response>::value
  >
{
};

template<>
struct is_service<rosgame_bridge::srv::RosgameRegister>
  : std::true_type
{
};

template<>
struct is_service_request<rosgame_bridge::srv::RosgameRegister_Request>
  : std::true_type
{
};

template<>
struct is_service_response<rosgame_bridge::srv::RosgameRegister_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // ROSGAME_BRIDGE__SRV__DETAIL__ROSGAME_REGISTER__TRAITS_HPP_
