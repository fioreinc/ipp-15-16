#include "SensorControl.h"

SensorControl::SensorControl(){
    for(int i = 0; i < NUM_SENSORS; i++){
        int pin = SENSOR_BASE_PIN + i;
        sensors[i] = new SensorObj(pin);
    }
}

float SensorControl::readSingle(int index){
    if(index >= NUM_SENSORS){
        index = NUM_SENSORS - 1;
    }
    return this->averageAnalog(SENSOR_BASE_PIN + index);
}

void SensorControl::readAll(float results[NUM_SENSORS]){
    for(int i = SENSOR_BASE_PIN; i < SENSOR_BASE_PIN + NUM_SENSORS; i++){
        results[i - SENSOR_BASE_PIN] = this->averageAnalog(i);
    }
}

/* Average the analog reading to eliminate some of the noise.
   Then convert the analog reading to a voltage, and return voltage. */
float SensorControl::averageAnalog(int pin) {
    float v = 0.0;
    int iterations = 5;
    for (int i = 0; i < iterations; i++){
        v += analogRead(pin);
    }
    return (v / iterations) * (5.0 / 1023.0);
}
