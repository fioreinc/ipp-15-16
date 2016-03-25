#include <Servo.h>
#include "ServoControl.h"
#include "SensorControl.h"


ServoControl* servo_control;
SensorControl* sensor_control;

void setup() {
    Serial.begin(9600);
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

float target[5] = {1, 1, 1, 1, 1};

float target_voltage = 4;
int reached_target_voltage = 0;

void loop() {
    int speed = 5;
    //Read all of the sensors, and if any of them are > target voltage, stop
    float result[NUM_SENSORS];
    sensor_control->readAll(result);
    for(int i = 0; i < NUM_SENSORS; i++){
        if(result[i] >= target_voltage){
            reached_target_voltage = 1;
            Serial.print("Voltage threshold reached on pin: ");
            Serial.print(reached_target_voltage);
            Serial.print("\n");
        }
    }

    if(!reached_target_voltage){
        int result[NUM_SERVOS];
        servo_control->gripTo(target, speed, result);
        for(int i = 0; i < NUM_SERVOS; i++){
            if(result[i]){
                if(target[i] == 0){
                    target[i] = 1;
                }
                else {
                    target[i] = 0;
                }
            }
        }
    }
}
