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

//float target[NUM_SERVOS] = {.5, .9, .9, .9, .9};

float target_voltage = .40;
int reached_target_voltage = 0;

bool allServosAtTarget(int result[NUM_SERVOS]){
    for(int i = 0; i < NUM_SERVOS; i++){
        if(result[i] == 0){
            return false;
        }
    }
    return true;
}

void reset(){
    bool all_reached = false;
    float target[NUM_SERVOS] = {0, 0, 0, 0, 0};
    int result[NUM_SERVOS];
    //while(!allServosAtTarget(result)){
    while(1){
        servo_control->gripTo(target, 2, result);
        String cmd = "";
        if(serial_comm->getCmdIfAvailable(cmd) != -1){
            if(cmd == "exitreset"){
                return;
            }
        }
    }
}

void mario(){

}

bool checkReset(){
    String cmd = "";
    if(serial_comm->getCmdIfAvailable(cmd) == -1){
        return false;
    }

    if(cmd == "reset"){
        reset();
        return true;
    }

    return false;
}

void openClose(){
    int result[NUM_SERVOS];
    int speed = 2;
    float target[NUM_SERVOS] = {0, 0, 0, 0, 0};
    while(1){
        if(checkReset()){
            return;
        }
        servo_control->gripTo(target, speed, result);
        for(int i = 1; i < NUM_SERVOS; i++){
            if(result[i]){
                if(target[i] == 1){
                    target[i] = 0;
                }
                else {
                    target[i] = 1;
                }
            }
        }
    }
}

void gripCoffee(){
    float voltages[NUM_SERVOS];
    int result[NUM_SERVOS];
    int speed = 2;
    float target[NUM_SERVOS] = {.5, 1, 1, 1, 1};
    float threshold = 1;
    while(1){
        if(checkReset()){
            return;
        }

        sensor_control->readAll(voltages);
        Serial.print("Thumb: ");
        Serial.print(voltages[0]);
        Serial.print("\nRing: ");
        Serial.print(voltages[3]);
        Serial.print("\n");
        for(int i = 0; i < NUM_SENSORS; i++){
            if(voltages[i] >= threshold){
                Serial.print("Threshold reached on ");
                Serial.print(i);
                Serial.print(" Value=");
                Serial.print(voltages[i]);
                Serial.print("\n");
                return;
            }
        }
        servo_control->gripTo(target, speed, result);
    }
}

void readSensors(){
    while(1){
        float voltages[NUM_SERVOS];
        sensor_control->readAll(voltages);
        Serial.print(voltages[3]);
        Serial.print("\n");
    }
}




void execCommand(String &cmd){
    if(cmd == "openclose"){
        openClose();
    }
    else if(cmd == "reset"){
        reset();
    }
    else if(cmd == "gripcoffee"){
        gripCoffee();
    }
    else if(cmd == "readsensors"){
        readSensors();
    }
    else if(cmd == "Mario"){
        mario();
    }
}

void loop() {
    String cmd;
    if(serial_comm->getCmdIfAvailable(cmd) != -1){
        execCommand(cmd);
    }
    return;
/*
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
*/
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

    /*
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
    */

        /*
    if(!reached_target_voltage){
        int result[NUM_SERVOS];
        servo_control->gripTo(target, speed, result);
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
    }
        */
}
