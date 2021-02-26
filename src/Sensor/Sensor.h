#include <Arduino.h>

#ifndef INFOB3IT_SENSOR_H
#define INFOB3IT_SENSOR_H

class Sensor { 

protected:
    // Primitive type therefore no reference
    int pinNumber;

public:
    // Constructor
    Sensor(int pinNumber);
};

#endif //INFOB3IT_SENSOR_H