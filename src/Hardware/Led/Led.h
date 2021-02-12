#include "Arduino.h"

#ifndef STICKUINO_LED_H
#define STICKUINO_LED_H


class Led {
private:
    int pinNumber;

public:
    Led(int pinNumber);
    void on();
    void off();
    void flash(int amount = 1, int flashSpeed = 250);
};


#endif //STICKUINO_LED_H
