#include <Arduino.h>
#include "BinarySwitch/BinarySwitch.h"

BinarySwitch::BinarySwitch(int pinNumber) { 
    // Set attribute pinNumber to value passed to constructor
    this->pinNumber = pinNumber;
    // Set up for LightSensor use
    pinMode(pinNumber,INPUT);
};

// Methods
bool BinarySwitch::getState(){
    return !digitalRead(this->pinNumber);
};

bool BinarySwitch::hasMillis(){
    return this->millisSet;
}

void BinarySwitch::stopTimer(){
    this-> millisSet = false;
}

void BinarySwitch::setBeginMillis(unsigned long millis) {
    this->beginMillis = millis;
    this->millisSet = true;
};

unsigned long BinarySwitch::getPressedTime(unsigned long millis) {
    return millis - this->beginMillis;
};