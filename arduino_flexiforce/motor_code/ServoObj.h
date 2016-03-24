#ifndef SERVO_OBJ_H
#define SERVO_OBJ_H

#include <Servo.h>

class ServoObj{

    public:
        ServoObj();
        Servo* obj;
        int pos;
};

#endif
