#include <Arduino.h>

#ifndef INFOB3IT_LED_H
#define INFOB3IT_LED_H

class Led { 

private:
    // Primitive type therefore no reference
    int pinNumber;

public:
    // Constructor
    Led(int pinNumber);
    // Methods
    void off();
    void on(); 
    void toggle();
    void flash(int amount = 1, int flashSpeed = 250);
};

#endif //INFOB3IT_LED_H