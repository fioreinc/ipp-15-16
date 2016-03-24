#ifndef SERVO_CONTROL_H
#define SERVO_CONTROL_H

#define NUM_SERVOS 5
#define SERVO_BASE_PIN 5

#define MAX_POS 180
#define MIN_POS 0

#include <Servo.h>
#include "ServoObj.h"
#include <Arduino.h>


class ServoControl{
    ServoObj* servos[NUM_SERVOS];

    void initServoObj(ServoObj* servo_obj, int pin);
    int internalGripTo(float depth, int speed, ServoObj* servo);


    public:
        ServoControl();
        void initServos();
        void gripTo(float depth[NUM_SERVOS], int speed, int results[NUM_SERVOS]);
};



#endif
