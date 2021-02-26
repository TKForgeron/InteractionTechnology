#include <Arduino.h>
#include "Sensor.h"

Sensor::Sensor(int pinNumber){
    this->pinNumber = pinNumber;    // Set attribute pinNumber to value passed to constructor
    pinMode(pinNumber,INPUT);      // Set up for Sensor use
};