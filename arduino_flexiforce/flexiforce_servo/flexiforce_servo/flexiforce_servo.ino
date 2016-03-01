#include <Servo.h>

#define MAX_POS 180
#define MIN_POS 0

#define PIN_PRESSURE 0

#define NUM_SERVOS 4
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

void setup() {
    Serial.begin(9600);
    for(int i = 0; i < NUM_SERVOS; i++){
        int pin = SERVO_BASE_PIN + i;
        init_servo_obj(&servos[i], pin);
    }

    for(int i = 0; i < NUM_SERVOS; i++){
        Serial.println(servos[i].obj->attached());
    }
}


/*
 * float        depth   Target depth to turn towards. Ranges from 0-1 where 1 is fully gripped and 0 is fully relaxed
 * int          speed   Speed at which to head towards the target, in tenths of degrees per millisecond
 * ServoObj*    servo   Pointer to the ServoObj that we're trying to control
 *
 * return       boolean indicating whether or not the servo has reached the target
*/
int grip_to(float depth, int speed, ServoObj* servo){
    if(depth > 1) depth = 1;
    if(depth < 0) depth = 0;
    int target_pos = depth*(MAX_POS - MIN_POS) + MIN_POS;

    int bounced = 1; //Boolean tracking if it was above and below the target in one iteration. If so, we're at the target
    if(servo->pos < target_pos){
        servo->pos += speed;
        bounced = !bounced;
    }
    if(servo->pos > target_pos){
        servo->pos -= speed;
        bounced = !bounced;
    }
    if(bounced){
        servo->pos = target_pos;
    }
    delay(10);


    if(servo->pos == target_pos){
        return 1;
    }

    servo->obj->write(servo->pos);
    return 0;

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

float target = 1;

void loop() {
    int speed = 1;
    for(int i = 0; i < NUM_SERVOS; i++){
        while(!grip_to(target, speed, &servos[i]));
    }

    if(target == 1){
        target = 0;
    }
    else{
        target = 1;
    }
}
