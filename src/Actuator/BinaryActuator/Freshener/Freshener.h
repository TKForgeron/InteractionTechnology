#include <Arduino.h>
#include "../BinaryActuator.h"


#ifndef INFOB3IT_FRESHENER_H
#define INFOB3IT_FRESHENER_H

enum State{notInUse, inUse, triggered, menu};
enum ManualSprayDelay{low = 30, medium = 60, high = 90};

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
    // Attributes
    ManualSprayDelay manualSprayDelay;
    unsigned long timesPulled;
    unsigned long timeInUse;
    unsigned long spraysLeft;
};

#endif //INFOB3IT_FRESHENER_Hc