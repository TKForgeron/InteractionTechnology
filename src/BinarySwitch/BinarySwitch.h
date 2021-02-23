#include <Arduino.h>

#ifndef INFOB3IT_BINARYSWITCH_H
#define INFOB3IT_BINARYSWITCH_H

class BinarySwitch { 

private:
    // Primitive type therefore no reference
    int pinNumber;
    unsigned long pressedMillis = 0;
    unsigned long beginMillis = 0;
    unsigned long endMillis = 0;

public:
    // constructor
    BinarySwitch(int pinNumber, bool isPressed, unsigned long pressedMillis);
    // Methods
    bool getState();
};

#endif //INFOB3IT_BINARYSWITCH_H