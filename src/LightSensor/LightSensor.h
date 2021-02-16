#include <Arduino.h>

#ifndef INFOB3IT_LIGHTSENSOR_H
#define INFOB3IT_LIGHTSENSOR_H

class LightSensor { 

private:
    // Primitive type therefore no reference
    int pinNumber;

public:
    // Constructor
    LightSensor(int pinNumber);
    // Methods
    int getValue();
    bool activateCondition(int threshold = 500);
    void consoleWrite(int writeSpeed);
};

#endif //INFOB3IT_LIGHTSENSOR_H