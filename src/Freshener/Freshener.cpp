#include <Arduino.h>
#include "Freshener.h"

Freshener::Freshener(){
    this->timeInUse = 0;
    this->timesPulled = 0;
    this->state = notInUse;
}

State Freshener::getState() {
    return this->state;
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