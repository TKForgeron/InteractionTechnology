#include <Arduino.h>
#include "LightSensor.h"


LightSensor::LightSensor(int pinNumber) : Sensor(pinNumber) {
};

int LightSensor::getValue(){
    return analogRead(this->pinNumber);
};

bool LightSensor::thresholdReached(int threshold){
    return this->getValue() > threshold;   
}