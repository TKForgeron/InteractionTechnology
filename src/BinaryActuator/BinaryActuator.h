#include <Arduino.h>

#ifndef INFOB3IT_BINARYACTUATOR_H
#define INFOB3IT_BINARYACTUATOR_H

class BinaryActuator { 

protected:
    // Primitive type therefore no reference
    int pinNumber;

public:
    // Constructor
    BinaryActuator(int pinNumber);
    // Methods
    void off();
    void on();
    void toggle();
};

#endif //INFOB3IT_BINARYACTUATOR_H