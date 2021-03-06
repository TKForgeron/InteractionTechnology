#include <Arduino.h>
#include "../BinaryActuator.h"


#ifndef INFOB3IT_FRESHENER_H
#define INFOB3IT_FRESHENER_H

enum State{notInUse, inUse, triggered};

class Freshener : public BinaryActuator { 

private:
    State state;

public:
    // Constructor
    Freshener(int pinNumber);
    // Methods
    State getState();
    void spray(int amount);
    void setState(State s);
    void reset();
    void increaseTimesPulled(int distanceThreshold, int distance);
    // Attributes
    unsigned long timesPulled;
    unsigned long timeInUse;
};

#endif //INFOB3IT_FRESHENER_H