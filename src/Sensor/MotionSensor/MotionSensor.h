#include <Arduino.h>
#include "../Sensor.h"

#ifndef INFOB3IT_MOTIONSENSOR_H
#define INFOB3IT_MOTIONSENSOR_H

class MotionSensor : public Sensor {
    
public:
    // Constructor
    MotionSensor(int pinNumber);
    // Methods
    bool getState();
    // Attributes
    bool state;
};

#endif //INFOB3IT_MOTIONSENSOR_H