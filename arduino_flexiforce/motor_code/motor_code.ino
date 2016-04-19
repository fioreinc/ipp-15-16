#include "ServoControl.h"
#include "SensorControl.h"
#include "SerialComm.h"


ServoControl* servo_control;
SensorControl* sensor_control;
SerialComm* serial_comm;

void setup() {
    serial_comm = new SerialComm();
    servo_control = new ServoControl();
    sensor_control = new SensorControl();
}

void readXBee(){
    char c;
    while(Serial.available() > 0){
        c = Serial.read();
        Serial.write(c);
    }
}

float target[NUM_SERVOS] = {.5, .9, .9, .9, .9};

float target_voltage = .40;
int reached_target_voltage = 0;

void loop() {
    int speed = 1;
    //Read all of the sensors, and if any of them are > target voltage, stop
    float result[NUM_SENSORS];
    sensor_control->readAll(result);
    int changed = 0;
    //Serial.println(result[4]);
    for(int i = 0; i < NUM_SENSORS; i++){
        /*
        if(result[i] >= target_voltage){
            reached_target_voltage = 1;
        }
        */
    }
    if(result[0] >= target_voltage){
        reached_target_voltage = 1;
    }
    Serial.println(result[0]);
    /*
    if(changed){
        reached_target_voltage = 1;
    }
    else{
        reached_target_voltage = 0;
    }
    */

    String cmd;
    if(serial_comm->getCmdIfAvailable(cmd) != -1){
        if(cmd == "stop"){
            reached_target_voltage = 1;
        }
        if(cmd == "start"){
            reached_target_voltage = 0;
        }
        if(cmd == "reset"){
            while(1){
                float target[NUM_SERVOS] = {.3, 0, 0, 0, 0};
                int result[NUM_SERVOS];
                servo_control->gripTo(target, 2, result);
            }
        }
    }

    if(!reached_target_voltage){
        int result[NUM_SERVOS];
        servo_control->gripTo(target, speed, result);
        /*
        for(int i = 1; i < NUM_SERVOS; i++){
            if(result[i]){
                if(target[i] == .7){
                    target[i] = 0;
                }
                else {
                    target[i] = .7;
                }
            }
        }
        */
    }
}
