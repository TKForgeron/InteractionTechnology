#include <Arduino.h>
#include "LightSensor.h"

LightSensor::LightSensor(int pinNumber){
    // Set attribute pinNumber to value passed to constructor
    this->pinNumber = pinNumber;
    // Set up for LightSensor use
    pinMode(pinNumber,INPUT);
};

void LightSensor::setInitialValue(){
    // Get initial light value
    this->initialValue = analogRead(this->pinNumber);
}

int LightSensor::getValue(){
    return analogRead(this->pinNumber);
};

// bool LightSensor::thresholdReached(int threshold){
//     Serial.print("getValue(): ");
//     Serial.println(this->getValue());
//     return this->getValue() - this->initialValue > threshold;
// };

bool LightSensor::thresholdReached(int threshold){
    return this->getValue() > threshold;   
}