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
    int result[NUM_SERVOS];
    int speed = 2;
    float target[NUM_SERVOS] = {0, 1, 0, 1, 1};
    while(1){
        if(checkReset()){
            return;
        }
        servo_control->gripTo(target, speed, result);
    }
}

void lobo(){
    int result[NUM_SERVOS];
    int speed = 2;
    float target[NUM_SERVOS] = {.3, 0, .5, .5, 0};
    while(1){
        if(checkReset()){
            return;
        }
        servo_control->gripTo(target, speed, result);
    }
}

void downFinger(int index){
    int result[NUM_SERVOS];
    int speed = 2;
    float target[NUM_SERVOS] = {0, 0, 0, 0, 0};
    target[index] = .8;
    while(1){
        if(checkReset()){
            return;
        }
        servo_control->gripTo(target, speed, result);
    }
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
        for(int i = 0; i < NUM_SERVOS; i++){
            if(result[i]){
                if(target[i] == .8){
                    target[i] = 0;
                }
                else {
                    target[i] = .8;
                }
            }
        }
        /*
        if(result[0]){
            if(target[0] == 0){
                target[0] = .8;
            }
            else{
                target[0] = 0;
            }
        }
        */
    }
}

void gripEraser(){//Good
    int speed = 2;
    float target[NUM_SERVOS] = {.5, 1, 1, 1, 1};
    float threshold = .8;
    execTestCase(target, speed, threshold, "Grip Eraser");
}

void gripWater(){//Good
    int speed = 2;
    float target[NUM_SERVOS] = {.5, .8, .8, .8, .8};
    float threshold = .8;
    execTestCase(target, speed, threshold, "Grip Water");
}

void gripThermos(){
    int speed = 2;
    float target[NUM_SERVOS] = {.5, .6, .6, .6, .6};
    float threshold = 1.4;
    execTestCase(target, speed, threshold, "Grip Thermos");
}

void gripCoke(){//Good
    int speed = 2;
    float target[NUM_SERVOS] = {.55, .55, .55, .55, .55};
    float threshold = 1.3;
    execTestCase(target, speed, threshold, "Grip Coke");
}

void gripFullWater(){
    int speed = 2;
    float target[NUM_SERVOS] = {.55, .65, .65, .65, .65};
    float threshold = 1.6;
    execTestCase(target, speed, threshold, "Grip Coke");
}

void gripFullTea(){//Good
    int speed = 2;
    float target[NUM_SERVOS] = {.55, .55, .55, .55, .55};
    float threshold = .8;
    execTestCase(target, speed, threshold, "Grip Full Tea");
}

void gripEmptyTea(){ //Good
    int speed = 2;
    float target[NUM_SERVOS] = {.4, .65, .65, .65, .65};
    float threshold = .6;
    execTestCase(target, speed, threshold, "Grip Empty Tea");
}

void crushEmptyTea(){
    int speed = 2;
    float target[NUM_SERVOS] = {.4, .9, .9, .9, .9};
    float threshold = 3;
    execTestCase(target, speed, threshold, "Crush Empty Tea");
}

//t_start is the time that the test case was started
void printSensorReading(float voltages[NUM_SERVOS], unsigned long t_start){
    unsigned long curr_t = millis();
    unsigned long relative_t = curr_t - t_start;
    Serial.print(relative_t);
    for(int i = 0; i < NUM_SERVOS; i++){
        Serial.print(",");
        Serial.print(voltages[i]);
    }
    Serial.print("\n");
}

void execTestCase(float target[NUM_SERVOS], int speed, float threshold, String test_case_name){
    float voltages[NUM_SERVOS];
    int result[NUM_SERVOS];
    unsigned long t_start = millis();
    Serial.print("Test Case: " + test_case_name + "\n");
    Serial.print("Threshold: ");
    Serial.print(threshold);
    Serial.print("\n");
    while(1){
        if(checkReset()){
            return;
        }

        sensor_control->readAll(voltages);
        printSensorReading(voltages, t_start);
        for(int i = 0; i < NUM_SENSORS; i++){
            if(voltages[i] >= threshold){
                return;
            }
        }
        servo_control->gripTo(target, speed, result);
    }
}

void execCommand(String &cmd){
    if(cmd == "openclose"){
        openClose();
    }
    else if(cmd == "reset"){
        reset();
    }
    else if(cmd == "gripCoke"){
        gripCoke();
    }
    else if(cmd == "gripFullTea"){
        gripFullTea();
    }
    else if(cmd == "gripEmptyTea"){
        gripEmptyTea();
    }
    else if(cmd == "crushEmptyTea"){
        crushEmptyTea();
    }
    else if(cmd == "gripWater"){
        gripWater();
    }
    else if(cmd == "gripEraser"){
        gripEraser();
    }
    else if(cmd == "gripThermos"){
        gripThermos();
    }
    else if(cmd == "gripFullWater"){
        gripFullWater();
    }
    else if(cmd == "downPinky"){
        downFinger(4);
    }
    else if(cmd == "downRing"){
        downFinger(3);
    }
    else if(cmd == "downMiddle"){
        downFinger(2);
    }
    else if(cmd == "downIndex"){
        downFinger(1);
    }
    else if(cmd == "downThumb"){
        downFinger(0);
    }
    /*Easter Eggs ;) */
    else if(cmd == "mario"){
        mario();
    }
    else if(cmd == "lobo"){
        lobo();
    }
}

void loop() {
    String cmd;
    if(serial_comm->getCmdIfAvailable(cmd) != -1){
        execCommand(cmd);
    }
    return;
}
