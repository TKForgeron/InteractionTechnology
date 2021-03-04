#include <Arduino.h>

#ifndef INFOB3IT_FRESHENER_H
#define INFOB3IT_FRESHENER_H

enum State{notInUse, inUse, triggered};

class Freshener { 

private:
    State state;

public:
    // Constructor
    Freshener();
    // Methods
    State getState();
    void setState(State s);
    void reset();
    void increaseTimesPulled(int distanceThreshold, int distance);
    // Attributes
    int timesPulled;
    unsigned long timeInUse;
};

#endif //INFOB3IT_FRESHENER_H