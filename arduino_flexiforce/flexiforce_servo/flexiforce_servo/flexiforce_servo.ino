// 2/18/2016 Tested successfully with one individual flexiforce sensor
#include <Servo.h>

int is_moving = 1;
Servo myservo;

void setup() {

  Serial.begin(9600);
  myservo.attach(9);
}

/* Average the analog reading to eliminate some of the noise.
   Then convert the analog reading to a voltage, and return voltage. */

void move_servo() {

  int pos = 0;

  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }

  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}

float averageAnalog(int pin) {
  float v = 0.0;
  for (int i = 0; i < 5; i++) v += analogRead(pin);
  return (v / 5) * (5.0 / 1023.0);
}

void loop() {

  float curr_reading = averageAnalog(0);
  Serial.print("A0 : ");
  Serial.print(curr_reading);
  Serial.println(" volts");

  if(curr_reading > 2.0){
    is_moving = 0;
  }

  if (is_moving){

    move_servo();
  }

  /*
    Serial.print("A1 : ");
    Serial.print(averageAnalog(1));
    Serial.println(" lbs");

    Serial.print("A2 : ");
    Serial.print(averageAnalog(2));
    Serial.println(" lbs");

    Serial.print("A3 : ");
    Serial.print(averageAnalog(3));
    Serial.println(" lbs");

    Serial.print("A4 : ");
    Serial.print(averageAnalog(4));
    Serial.println(" lbs");

    Serial.print("A5 : ");
    Serial.print(averageAnalog(5));
    Serial.println(" lbs");
  */

  delay(200);        // delay in between reads (200 milliseconds)
}
