#include <Servo.h>

#define MAX_POS 180
#define MIN_POS 0

#define PIN_PRESSURE 0

#define NUM_SERVOS 5
#define SERVO_BASE_PIN 5

int is_moving = 1;

typedef struct ServoObj{
    Servo* obj;
    int pos;
} ServoObj;

ServoObj servos[NUM_SERVOS];

void init_servo_obj(ServoObj* servo_obj, int pin){
    servo_obj->obj = new Servo;
    servo_obj->obj->attach(pin);
    servo_obj->obj->write(0);
    servo_obj->pos = 0;
}

void init_servos(){
    for(int i = 0; i < NUM_SERVOS; i++){
        int pin = SERVO_BASE_PIN + i;
        init_servo_obj(&servos[i], pin);
    }
    /*
    for(int i = 0; i < NUM_SERVOS; i++){
        Serial.println(servos[i].obj->attached());
    }
    */
}

void setup() {
    Serial.begin(9600);
    init_servos();
}

int internal_grip_to(float depth, int speed, ServoObj* servo){
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

/*
 * float        depth   Target depth to turn towards. Ranges from 0-1 where 1 is fully gripped and 0 is fully relaxed
 * int          speed   Speed ranges from 1 to 10
 * ServoObj*    servo   Pointer to the ServoObj that we're trying to control
 *
 * return       boolean indicating whether or not the servo has reached the target
*/
int grip_to(float depth[], int speed, ServoObj servo[NUM_SERVOS], int results[NUM_SERVOS]){
    for(int i = 0; i < NUM_SERVOS; i++){
        results[i] = internal_grip_to(depth[i], speed, &servo[i]);
    }

    if(speed < 1) speed = 1;
    if(speed > 10) speed = 10;

    float min_delay = 11; //ms
    delay(min_delay*10/speed);
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
    int speed = 10;
    float sensor_val = average_analog(0);
    float sensor_val2 = average_analog(1);

    if(sensor_val >= target_voltage || sensor_val2 >= target_voltage){
        reached_target_voltage = 1;
    }

    if(!reached_target_voltage){
        int result[NUM_SERVOS];
        grip_to(target, speed, servos, result);
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
