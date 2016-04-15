#ifndef SERVO_OBJ_H
#define SERVO_OBJ_H

#include <Servo.h>

class ServoObj{

    public:
        ServoObj(int pin, bool is_inverted, bool is_thumb);
        Servo* obj;
        int pos;
        int is_thumb;
        bool is_inverted; //For some fingers, 1 = open and 0 = closed
};

#endif
