#ifndef SERVO_OBJ_H
#define SERVO_OBJ_H

#include <Servo.h>

class ServoObj{

    public:
        ServoObj(int pin);
        Servo* obj;
        int pos;
};

#endif
