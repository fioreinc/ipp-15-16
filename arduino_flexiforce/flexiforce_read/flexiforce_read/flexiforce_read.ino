
void setup() {

  Serial.begin(9600);

}

// average the analog reading to eliminate some of the noise
float averageAnalog(int pin) {
  float v = 0.0;
  for (int i = 0; i < 5; i++) v += analogRead(pin);
  return (v / 5)*(5.0/1023.0);        // convert the analog reading to a voltage, return the voltage

}

void loop() {
  
  // print out the values read by the 5 flexiforce sensors
  Serial.println(averageAnalog(0));
  Serial.println(averageAnalog(1));
  Serial.println(averageAnalog(2));
  Serial.println(averageAnalog(3));
  Serial.println(averageAnalog(4));

  delay(100);        // delay in between reads for stability (100 milliseconds)
}
