#include <Arduino.h>
#include "../Sensor.h"
#include "../../Timer/Timer.h"

#ifndef INFOB3IT_MOTIONSENSOR_H
#define INFOB3IT_MOTIONSENSOR_H

class MotionSensor : public Sensor {
    
private:
    int motionCount;
    int state;
    int currentState;
    int previousState;

public:
    // Constructor
    MotionSensor(int pinNumber);
    // Methods
    int motionCounter();
    void reset();

};

#endif //INFOB3IT_MOTIONSENSOR_H