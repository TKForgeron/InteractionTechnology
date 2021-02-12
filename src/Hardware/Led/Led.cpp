#include <Arduino.h>
#include "Led.h"

Led::Led(int pinNumber) {
    this->pinNumber = pinNumber;
    pinMode(pinNumber, OUTPUT);
}

void Led::on() {
    digitalWrite(this->pinNumber, HIGH);
};

void Led::off() {
    digitalWrite(this->pinNumber, LOW);
};

void Led::flash(int amount, int flashSpeed) {
    for (int i = 0; i < amount; i++) {
        this->on();
        delay((int) flashSpeed/2);
        this->off();
        delay((int) flashSpeed/2);
    }
};
