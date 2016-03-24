#include "ServoControl.h"

ServoControl::ServoControl(){
    this->initServos();
}

void ServoControl::initServos(){
    for(int i = 0; i < NUM_SERVOS; i++){
        servos[i] = new ServoObj();
        int pin = SERVO_BASE_PIN + i;
        this->initServoObj(servos[i], pin);
    }
}

void ServoControl::initServoObj(ServoObj* servo_obj, int pin){
    servo_obj->obj = new Servo;
    servo_obj->obj->attach(pin);
    servo_obj->obj->write(0);
    servo_obj->pos = 0;
}

/*
 * float[]  depth   Depths to move each of the servos towards. sizeof(depth) must be equal to NUM_SERVOS.
 *                    Ranges from 0-1, where 1 is fully gripped, and 0 is fully relaxed
 * int      speed   Speed ranges from 1 to 10, with 10 being max speed
 * 
 * int[]     results Array of ints to tell the calling function which servos have reached their target
*/
void ServoControl::gripTo(float depth[NUM_SERVOS], int speed, int results[NUM_SERVOS]){
    for(int i = 0; i < NUM_SERVOS; i++){
        results[i] = internalGripTo(depth[i], speed, this->servos[i]);
    }

    if(speed < 1) speed = 1;
    if(speed > 10) speed = 10;

    float min_delay = 11; //ms
    delay(min_delay*10/speed);
}


int ServoControl::internalGripTo(float depth, int speed, ServoObj* servo){
    if(depth > 1) depth = 1;
    if(depth < 0) depth = 0;
    int target_pos = depth*(MAX_POS - MIN_POS) + MIN_POS;

    if(servo->pos < target_pos){
        servo->pos++;
    }
    if(servo->pos > target_pos){
        servo->pos--;
    }


    servo->obj->write(servo->pos);

    return (servo->pos == target_pos);
}

