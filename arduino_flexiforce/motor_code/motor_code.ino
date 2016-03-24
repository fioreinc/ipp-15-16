#include <Servo.h>
#include "ServoControl.h"


#define PIN_PRESSURE 0

#define NUM_SENSORS 5
#define SENSOR_BASE_PIN 0

int is_moving = 1;

ServoControl* srv_control;

void setup() {
    Serial.begin(9600);
    srv_control = new ServoControl();
}

/* Average the analog reading to eliminate some of the noise.
   Then convert the analog reading to a voltage, and return voltage. */
float average_analog(int pin) {
    float v = 0.0;
    int iterations = 5;
    for (int i = 0; i < iterations; i++){
        v += analogRead(pin);
    }
    return (v / iterations) * (5.0 / 1023.0);
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
    for(int i = SENSOR_BASE_PIN; i < SENSOR_BASE_PIN + NUM_SERVOS; i++){
        float reading = average_analog(i);
        if(reading >= target_voltage){
            reached_target_voltage = 1;
            Serial.print("Voltage threshold reached on pin: ");
            Serial.print(reached_target_voltage);
            Serial.print("\n");
        }
    }

    if(!reached_target_voltage){
        int result[NUM_SERVOS];
        srv_control->gripTo(target, speed, result);
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
