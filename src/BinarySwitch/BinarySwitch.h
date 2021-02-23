#include <Arduino.h>

#ifndef INFOB3IT_BINARYSWITCH_H
#define INFOB3IT_BINARYSWITCH_H

class BinarySwitch { 

private:
    // Primitive type therefore no reference
    int pinNumber;
    int startPressed = 0;    // the moment the button was pressed
    int endPressed = 0;      // the moment the button was released
    int holdTime = 0;        // how long the button was hold
    int idleTime = 0;        // how long the button was idle

public:
    // constructor
    BinarySwitch(int pinNumber);
    // Methods
    bool getState();
    void updateState();
    void updateCounter();
    // Properties
    int buttonState = 0;     // current state of the button
    int lastButtonState = 0; // previous state of the button
};

#endif //INFOB3IT_BINARYSWITCH_H