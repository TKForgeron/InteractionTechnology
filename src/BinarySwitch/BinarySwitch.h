#include <Arduino.h>

#ifndef INFOB3IT_BINARYSWITCH_H
#define INFOB3IT_BINARYSWITCH_H

class BinarySwitch { 

private:
    // Primitive type therefore no reference
    int pinNumber;
    unsigned long beginMillis = 0;

public:
    // constructor
    BinarySwitch(int pinNumber);
    // Methods
    bool getState();
    void setBeginMillis(unsigned long millis);
    unsigned long getPressedTime(unsigned long millis);
};

#endif //INFOB3IT_BINARYSWITCH_H