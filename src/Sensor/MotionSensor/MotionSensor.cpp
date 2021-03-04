#include <Arduino.h>
#include "MotionSensor.h"

MotionSensor::MotionSensor(int pinNumber) : Sensor(pinNumber) { 
};

// Methods
bool MotionSensor::getState(){
    this->state = digitalRead(this->pinNumber);
    return this->state;
}
