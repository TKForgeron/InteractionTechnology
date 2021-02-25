#include <Arduino.h>
#include "../BinaryActuator.h"

#ifndef INFOB3IT_MOSFET_H
#define INFOB3IT_MOSFET_H

class Mosfet : public BinaryActuator { 

public:
    // Constructor
    Mosfet(int pinNumber);
};

#endif //INFOB3IT_MOSFET_H