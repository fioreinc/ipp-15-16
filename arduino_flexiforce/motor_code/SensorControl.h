#ifndef SENSOR_CONTROL_H 
#define SENSOR_CONTROL_H

#define NUM_SENSORS 5
#define SENSOR_BASE_PIN 8

#include "SensorObj.h"
#include <Arduino.h>


class SensorControl{
    SensorObj* sensors[NUM_SENSORS];

    float averageAnalog(int pin);


    public:
        SensorControl();
        float readSingle(int index);
        void readAll(float results[NUM_SENSORS]);
};



#endif
