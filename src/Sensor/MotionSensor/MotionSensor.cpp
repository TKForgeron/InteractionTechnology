#include <Arduino.h>
#include "MotionSensor.h"

MotionSensor::MotionSensor(int pinNumber) : Sensor(pinNumber) { 
    this->pinNumber = pinNumber;
    pinMode(pinNumber, INPUT);
    this->motionCount = 0;
    this->state = LOW;
    this->currentState = 0;
    this->previousState = 0;
};

int MotionSensor::motionCounter() {

    if (digitalRead(this->pinNumber) == HIGH) { // motion detected
        if (this->state == LOW ) {
            // we have just turned on
            this->currentState = 1;
            this->state = HIGH;
            delay(1000);
        }
    } else {    // no motion detected
    if (this->state == HIGH){
        // we have just turned off
        this->currentState = 0;
        // We only want to print on the output change, not state
        this->state = LOW;
    }
    }

    if(this->currentState != this->previousState && this->currentState == 1){
        this->motionCount++;
        delay(400);
    }

    return this->motionCount;
}

void MotionSensor::reset() {
    this->motionCount = 0;
    this->state = LOW;
    this->currentState = 0;
    this->previousState = 0;
}