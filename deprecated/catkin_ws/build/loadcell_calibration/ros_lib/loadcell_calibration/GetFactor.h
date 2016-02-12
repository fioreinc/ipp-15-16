#ifndef _ROS_SERVICE_GetFactor_h
#define _ROS_SERVICE_GetFactor_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace loadcell_calibration
{

static const char GETFACTOR[] = "loadcell_calibration/GetFactor";

  class GetFactorRequest : public ros::Msg
  {
    public:
      float lbs_reading;

    GetFactorRequest():
      lbs_reading(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->lbs_reading);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->lbs_reading));
     return offset;
    }

    const char * getType(){ return GETFACTOR; };
    const char * getMD5(){ return "5f0e6a96bd902d97b0033da431e3f2f6"; };

  };

  class GetFactorResponse : public ros::Msg
  {
    public:
      float factor;
      bool is_done;

    GetFactorResponse():
      factor(0),
      is_done(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->factor);
      union {
        bool real;
        uint8_t base;
      } u_is_done;
      u_is_done.real = this->is_done;
      *(outbuffer + offset + 0) = (u_is_done.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_done);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->factor));
      union {
        bool real;
        uint8_t base;
      } u_is_done;
      u_is_done.base = 0;
      u_is_done.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_done = u_is_done.real;
      offset += sizeof(this->is_done);
     return offset;
    }

    const char * getType(){ return GETFACTOR; };
    const char * getMD5(){ return "d3ab040ca6fa857706b6944f2020aace"; };

  };

  class GetFactor {
    public:
    typedef GetFactorRequest Request;
    typedef GetFactorResponse Response;
  };

}
#endif
