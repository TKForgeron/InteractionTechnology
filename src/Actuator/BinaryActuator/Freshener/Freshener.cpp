#include <Arduino.h>
#include "Freshener.h"

Freshener::Freshener(int pinNumber) : BinaryActuator(pinNumber) {
    // this->pinNumber = pinNumber;
    // digitalWrite(pinNumber, OUTPUT);
    this->timeInUse = 0;
    this->timesPulled = 0;
    this->state = notInUse;
}

State Freshener::getState() {
    return this->state;
}

void Freshener::spray(int amount) {
    
    for (int i = 0; i < amount; i++) {
        this->on();
        delay(25000);
        this->off();
    }
    
}

void Freshener::setState(State s) {
    this->state = s;
}

void Freshener::reset() {
    this->timeInUse = 0;
    this->timesPulled = 0;   
    this->state = notInUse;
}

void Freshener::increaseTimesPulled(int distanceThreshold, int distance) {
    if (distance > distanceThreshold) {
        this->timesPulled++;
    }
}