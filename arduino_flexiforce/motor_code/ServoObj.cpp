#include "ServoObj.h"

ServoObj::ServoObj(int pin, bool is_inverted, bool is_thumb){
    int pulse_width_min = 620; //For HS55 servos (0 degrees = 600us)
    int pulse_width_max = 2380; //For HS55 servos (180 degrees = 2400us)
    this->is_thumb = is_thumb;
    this->is_inverted = is_inverted;
    this->obj = new Servo();
    this->obj->attach(pin, pulse_width_min, pulse_width_max);
    if(is_inverted){
        this->pos = 180;
    }
    else{
        this->pos = 0;
    }
    this->obj->write(this->pos);
}
