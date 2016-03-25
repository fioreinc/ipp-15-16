#include "ServoObj.h"

ServoObj::ServoObj(int pin){
    this->obj = new Servo();
    this->obj->attach(pin);
    this->obj->write(0);
    this->pos = 0;
}
