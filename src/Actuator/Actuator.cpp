#include <Arduino.h>
#include "Actuator.h"

Actuator::Actuator(int pinNumber){
    this->pinNumber = pinNumber;    // Set attribute pinNumber to value passed to constructor
    pinMode(pinNumber,OUTPUT);      // Set up for Actuator use
};