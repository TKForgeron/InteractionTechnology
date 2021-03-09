#include <Arduino.h>
#include "Freshener.h"

Freshener::Freshener(int pinNumber) : BinaryActuator(pinNumber) {
    this->manualSprayDelay = low;
    this->timeInUse = 0;
    this->timesPulled = 0;
    this->state = notInUse;
}

void Freshener::setState(State s) {
    this->state = s;
}

State Freshener::getState() {
    return this->state;
}

void Freshener::spray(int amount) {
    
    for (int i = 0; i < amount; i++) {
        this->on();
        delay(20000);
        this->off();
        delay(1000);
    }
    
}

void Freshener::reset() {
    this->timeInUse = 0;
    this->timesPulled = 0;   
    this->state = notInUse;
}

