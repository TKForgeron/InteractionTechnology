#include <Arduino.h>
#include "LightSensor.h"

LightSensor::LightSensor(int pinNumber){
    // Set attribute pinNumber to value passed to constructor
    this->pinNumber = pinNumber;
    // Set up for LightSensor use
    pinMode(pinNumber,INPUT);
};

int LightSensor::getValue(){
    int value = analogRead(this->pinNumber);
    return value;
};

bool LightSensor::activateCondition(int threshold){
    bool x = this->getValue() > threshold;
    return x;
};

void LightSensor::consoleWrite(int writeSpeed){
    // int value = this->getValue();
    // Serial.println(value);
    Serial.println(this->getValue());
}