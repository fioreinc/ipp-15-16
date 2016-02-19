// 2/18/2016 Tested successfully with one individual flexiforce sensor
#include <Servo.h>

#define MAX_POS 180
#define MIN_POS 0

int is_moving = 1;
Servo myservo;

void setup() {

  Serial.begin(9600);
  myservo.attach(9);
}

int pos = 0;

//Moves gradually towards the provided depth, where depth ranges from 0-1.
//1 is fully gripped
//0 is fully released
//Returns 1 if we have reached the targeted grip depth
int gripTo(float depth, int speed){
    if(depth > 1) depth = 1;
    if(depth < 0) depth = 0;
    int target_pos = depth*(MAX_POS - MIN_POS) + MIN_POS;

    int bounced = 1; //Boolean tracking if it was above and below the target in one interation. If so, we're at the target
    if(pos < target_pos){
        pos += speed;
        bounced = !bounced;
    }
    if(pos > target_pos){
        pos -= speed;
        bounced = !bounced;
    }
    if(bounced){
        pos = target_pos;
    }
    Serial.println(pos);

    if(pos == target_pos){
        return 1;
    }

    myservo.write(pos);
    return 0;

}

/* Average the analog reading to eliminate some of the noise.
   Then convert the analog reading to a voltage, and return voltage. */

float averageAnalog(int pin) {
  float v = 0.0;
  for (int i = 0; i < 5; i++) v += analogRead(pin);
  return (v / 5) * (5.0 / 1023.0);
}

float grips[] = {.5, .3, .9, 0, 1, .4, .8, .2, .7};
int grips_len = 9;
int curr_grip = 0;
int speed = 3;

void loop() {

    //float curr_reading = averageAnalog(0);
    //Serial.print("A0 : ");
    //Serial.print(curr_reading);
    //Serial.println(" volts");
   
    Serial.println(grips[curr_grip]);
    while(!gripTo(grips[curr_grip], speed));
    delay(1000);
    curr_grip++;
    if(curr_grip > grips_len){
        while(1);//Spin
    }
}
