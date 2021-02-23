#include <Arduino.h>
#include "BinarySwitch/BinarySwitch.h"

BinarySwitch::BinarySwitch(int pinNumber, bool isPressed, unsigned long pressedMillis) { 
    pinMode(this->pinNumber,INPUT);
};

// Methods
bool BinarySwitch::getState(){
    return digitalRead(this->pinNumber);
};