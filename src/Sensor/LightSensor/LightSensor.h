#include <Arduino.h>
#include "../Sensor.h"

#ifndef INFOB3IT_LIGHTSENSOR_H
#define INFOB3IT_LIGHTSENSOR_H

class LightSensor : public Sensor { 

public:
    int initialValue = 10;
    // Constructor
    LightSensor(int pinNumber);
    // Methods
    void setInitialValue();
    int getValue();
    bool thresholdReached(int threshold = 500);
};

#endif //INFOB3IT_LIGHTSENSOR_H