#include "ServoControl.h"
#include <Arduino.h>

ServoControl::ServoControl(){
    bool is_inverted = false;
    bool is_thumb = false; 
    for(int i = 0; i < NUM_SERVOS; i++){
        int pin = SERVO_BASE_PIN + i;
        if(i == 0 || i == 2 || i == 4){ //Middle finger, pinky, and thumb are inverted
            is_inverted = true;
        }
        else{
            is_inverted = false;
        }
        if(i == 0){
            is_thumb = true;
        }
        else{
            is_thumb = false;
        }
        servos[i] = new ServoObj(pin, is_inverted, is_thumb);
    }
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

    if(servo->is_inverted){
        depth = 1 - depth;
    }

    if(servo->is_thumb){
        depth *= .66;
    }

    int max_pos = MAX_POS;
    int min_pos = MIN_POS;
    if(servo->is_thumb){
        min_pos = 60;
    }

    int target_pos = depth*(max_pos - min_pos) + min_pos;

    if(servo->pos < target_pos){
        servo->pos++;
    }

    if(servo->pos > target_pos){
        servo->pos--;
    }

    servo->obj->write(servo->pos);

    return (servo->pos == target_pos);
}

