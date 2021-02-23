#include <Arduino.h>

#ifndef INFOB3IT_LIGHTSENSOR_H
#define INFOB3IT_LIGHTSENSOR_H

class LightSensor { 

private:
    // Primitive type therefore no reference
    int pinNumber;

public:
    int initialValue = 10;
    // Constructor
    LightSensor(int pinNumber);
    // Methods
    void setInitialValue();
    int getValue();
    bool thresholdReached(int threshold = 250);
};

#endif //INFOB3IT_LIGHTSENSOR_H