#include <Arduino.h>
#include "../Sensor.h"

#ifndef INFOB3IT_LIGHTSENSOR_H
#define INFOB3IT_LIGHTSENSOR_H

class LightSensor : public Sensor { 

public:
    // Constructor
    LightSensor(int pinNumber);
    // Methods
    int getValue();
    bool thresholdReached(int threshold = 500);
};

#endif //INFOB3IT_LIGHTSENSOR_H






