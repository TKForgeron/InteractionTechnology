#include <Arduino.h>

#ifndef INFOB3IT_ACTUATOR_H
#define INFOB3IT_ACTUATOR_H

class Actuator { 

protected:
    int pinNumber;

public:
    // Constructor
    Actuator(int pinNumber);
};

#endif //INFOB3IT_ACTUATOR_H
