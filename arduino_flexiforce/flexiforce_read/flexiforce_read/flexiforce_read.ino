// 2/18/2016 Tested successfully with one individual flexiforce sensor
void setup() {

  Serial.begin(9600);

}

/* Average the analog reading to eliminate some of the noise.
   Then convert the analog reading to a voltage, and return voltage. */
 
float averageAnalog(int pin) {
  float v = 0.0;
  for (int i = 0; i < 5; i++) v += analogRead(pin);
  return (v / 5)*(5.0/1023.0);

}

void loop() {
  
  Serial.print("A0 : ");
  Serial.print(averageAnalog(0));
  Serial.println(" lbs");
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
