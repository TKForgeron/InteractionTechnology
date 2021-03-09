#include <Arduino.h>
#include "../Actuator.h"

#ifndef INFOB3IT_BINARYACTUATOR_H
#define INFOB3IT_BINARYACTUATOR_H

class BinaryActuator : public Actuator { 

public:
    // Constructor
    BinaryActuator(int pinNumber);
    // Methods
    void off();
    void on();
    void toggle();
};

#endif //INFOB3IT_BINARYACTUATOR_H

