// Generated by gencpp from file loadcell_calibration/GetFactorResponse.msg
// DO NOT EDIT!


#ifndef LOADCELL_CALIBRATION_MESSAGE_GETFACTORRESPONSE_H
#define LOADCELL_CALIBRATION_MESSAGE_GETFACTORRESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace loadcell_calibration
{
template <class ContainerAllocator>
struct GetFactorResponse_
{
  typedef GetFactorResponse_<ContainerAllocator> Type;

  GetFactorResponse_()
    : factor(0.0)
    , is_done(false)  {
    }
  GetFactorResponse_(const ContainerAllocator& _alloc)
    : factor(0.0)
    , is_done(false)  {
    }



   typedef double _factor_type;
  _factor_type factor;

   typedef uint8_t _is_done_type;
  _is_done_type is_done;




  typedef boost::shared_ptr< ::loadcell_calibration::GetFactorResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::loadcell_calibration::GetFactorResponse_<ContainerAllocator> const> ConstPtr;

}; // struct GetFactorResponse_

typedef ::loadcell_calibration::GetFactorResponse_<std::allocator<void> > GetFactorResponse;

typedef boost::shared_ptr< ::loadcell_calibration::GetFactorResponse > GetFactorResponsePtr;
typedef boost::shared_ptr< ::loadcell_calibration::GetFactorResponse const> GetFactorResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::loadcell_calibration::GetFactorResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::loadcell_calibration::GetFactorResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace loadcell_calibration

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::loadcell_calibration::GetFactorResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::loadcell_calibration::GetFactorResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::loadcell_calibration::GetFactorResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::loadcell_calibration::GetFactorResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::loadcell_calibration::GetFactorResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::loadcell_calibration::GetFactorResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::loadcell_calibration::GetFactorResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d3ab040ca6fa857706b6944f2020aace";
  }

  static const char* value(const ::loadcell_calibration::GetFactorResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd3ab040ca6fa8577ULL;
  static const uint64_t static_value2 = 0x06b6944f2020aaceULL;
};

template<class ContainerAllocator>
struct DataType< ::loadcell_calibration::GetFactorResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "loadcell_calibration/GetFactorResponse";
  }

  static const char* value(const ::loadcell_calibration::GetFactorResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::loadcell_calibration::GetFactorResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float64 factor\n\
bool is_done\n\
\n\
";
  }

  static const char* value(const ::loadcell_calibration::GetFactorResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::loadcell_calibration::GetFactorResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.factor);
      stream.next(m.is_done);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct GetFactorResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::loadcell_calibration::GetFactorResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::loadcell_calibration::GetFactorResponse_<ContainerAllocator>& v)
  {
    s << indent << "factor: ";
    Printer<double>::stream(s, indent + "  ", v.factor);
    s << indent << "is_done: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.is_done);
  }
};

} // namespace message_operations
} // namespace ros

#endif // LOADCELL_CALIBRATION_MESSAGE_GETFACTORRESPONSE_H