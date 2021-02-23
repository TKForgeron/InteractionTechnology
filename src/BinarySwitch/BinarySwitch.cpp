#include <Arduino.h>
#include "BinarySwitch/BinarySwitch.h"

BinarySwitch::BinarySwitch(int pinNumber) { 
    pinMode(this->pinNumber,INPUT);
};

// Methods
bool BinarySwitch::getState(){
    return digitalRead(this->pinNumber);
};

bool BinarySwitch::hasMillis(){
    return this->millisSet;
}

void BinarySwitch::setBeginMillis(unsigned long millis) {
    this->beginMillis = millis;
    this->millisSet = true;
};

unsigned long BinarySwitch::getPressedTime(unsigned long millis) {
    return millis - this->beginMillis;
}