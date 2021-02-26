#include <Arduino.h>
#include "BinaryActuator.h"

BinaryActuator::BinaryActuator(int pinNumber) : Actuator(pinNumber) {
};

void BinaryActuator::on() {
    // Set voltage to high for attribute pinNumber
    digitalWrite(this->pinNumber, HIGH);
};

void BinaryActuator::off() {
    // Set voltage to low for attribute pinNumber
    digitalWrite(this->pinNumber, LOW);
};

void BinaryActuator::toggle(){
    // Set voltage to opposite of what it is now for attribute pinNumber
    int pin = this->pinNumber;
    bool ledState = digitalRead(pin);
    digitalWrite(pin, !ledState);
};