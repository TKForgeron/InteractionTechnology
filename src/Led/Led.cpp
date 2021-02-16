#include <Arduino.h>
#include "Led.h"

Led::Led(int pinNumber){
    // Set attribute pinNumber to value passed to constructor
    this->pinNumber = pinNumber;
    // Setup for led use to output
    pinMode(pinNumber,OUTPUT);

};

void Led::on() {
    // Set voltage to high for attribute pinNumber
    digitalWrite(this->pinNumber, HIGH);
};

void Led::off() {
    // Set voltage to low for attribute pinNumber
    digitalWrite(this->pinNumber, LOW);
};

void Led::flash(int amount, int flashSpeed){
    
    // Loop and flash
    for(int i=0; i < amount; i++){
        this->on();
        delay(flashSpeed);
        this->off();
        delay(flashSpeed);

    }

};

