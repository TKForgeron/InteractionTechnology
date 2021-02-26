#include <Arduino.h>
#include "Led.h"

#ifndef INFOB3IT_RGBLED_H
#define INFOB3IT_RGBLED_H

class RGBLed { 

private:
    // We do not want to redefine Led, * to create a reference
    Led *red;
    Led *green;
    Led *blue;

public: 
    // We do not want to redefine Led, * to create a reference
    RGBLed(Led *red, Led *green, Led *blue);
    void cyan();
    void magenta(); 
    void yellow(); 
    void white(); 
    void ambulance();

}; 

#endif //INFOB3IT_RGBLED_H