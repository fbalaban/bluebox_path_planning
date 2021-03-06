// Generated by gencpp from file waypoint_planning/Replan_Msg.msg
// DO NOT EDIT!


#ifndef WAYPOINT_PLANNING_MESSAGE_REPLAN_MSG_H
#define WAYPOINT_PLANNING_MESSAGE_REPLAN_MSG_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <waypoint_planning/Coordinates.h>

namespace waypoint_planning
{
template <class ContainerAllocator>
struct Replan_Msg_
{
  typedef Replan_Msg_<ContainerAllocator> Type;

  Replan_Msg_()
    : uav_id(0)
    , coordinates()  {
    }
  Replan_Msg_(const ContainerAllocator& _alloc)
    : uav_id(0)
    , coordinates(_alloc)  {
    }



   typedef int8_t _uav_id_type;
  _uav_id_type uav_id;

   typedef  ::waypoint_planning::Coordinates_<ContainerAllocator>  _coordinates_type;
  _coordinates_type coordinates;




  typedef boost::shared_ptr< ::waypoint_planning::Replan_Msg_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::waypoint_planning::Replan_Msg_<ContainerAllocator> const> ConstPtr;

}; // struct Replan_Msg_

typedef ::waypoint_planning::Replan_Msg_<std::allocator<void> > Replan_Msg;

typedef boost::shared_ptr< ::waypoint_planning::Replan_Msg > Replan_MsgPtr;
typedef boost::shared_ptr< ::waypoint_planning::Replan_Msg const> Replan_MsgConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::waypoint_planning::Replan_Msg_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::waypoint_planning::Replan_Msg_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace waypoint_planning

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'waypoint_planning': ['/home/fotis/Dev/Workspaces/ROS/bluebox_path_planning/src/waypoint_planning/msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::waypoint_planning::Replan_Msg_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::waypoint_planning::Replan_Msg_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::waypoint_planning::Replan_Msg_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::waypoint_planning::Replan_Msg_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::waypoint_planning::Replan_Msg_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::waypoint_planning::Replan_Msg_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::waypoint_planning::Replan_Msg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ba579b4b1534fcbd7ed9e29ed0638bff";
  }

  static const char* value(const ::waypoint_planning::Replan_Msg_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xba579b4b1534fcbdULL;
  static const uint64_t static_value2 = 0x7ed9e29ed0638bffULL;
};

template<class ContainerAllocator>
struct DataType< ::waypoint_planning::Replan_Msg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "waypoint_planning/Replan_Msg";
  }

  static const char* value(const ::waypoint_planning::Replan_Msg_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::waypoint_planning::Replan_Msg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int8 uav_id\n\
waypoint_planning/Coordinates coordinates\n\
================================================================================\n\
MSG: waypoint_planning/Coordinates\n\
float64 longitude\n\
float64 latitude\n\
";
  }

  static const char* value(const ::waypoint_planning::Replan_Msg_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::waypoint_planning::Replan_Msg_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.uav_id);
      stream.next(m.coordinates);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct Replan_Msg_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::waypoint_planning::Replan_Msg_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::waypoint_planning::Replan_Msg_<ContainerAllocator>& v)
  {
    s << indent << "uav_id: ";
    Printer<int8_t>::stream(s, indent + "  ", v.uav_id);
    s << indent << "coordinates: ";
    s << std::endl;
    Printer< ::waypoint_planning::Coordinates_<ContainerAllocator> >::stream(s, indent + "  ", v.coordinates);
  }
};

} // namespace message_operations
} // namespace ros

#endif // WAYPOINT_PLANNING_MESSAGE_REPLAN_MSG_H
