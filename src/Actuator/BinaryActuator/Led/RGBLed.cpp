#include <Arduino.h>
#include "RGBLed.h"

// We do not want to redefine Led, * to create a reference
RGBLed::RGBLed(Led *red, Led *green, Led *blue){
    this->red = red;
    this->green = green;
    this->blue = blue;
};


// RGBLed has three leds as attributes. From a led attribute we can execute the functions of the obj
void RGBLed::cyan(){
    this->red->off();
    this->green->on();
    this->blue->on();
};

void RGBLed::magenta(){
    this->green->off();
    this->red->on();
    this->blue->on();
};

void RGBLed::yellow(){
    this->blue->off();
    this->green->on();
    this->red->on();
};

void RGBLed::white(){
    this->blue->on();
    this->green->on();
    this->red->on();
};

void RGBLed::singleRed(){
    this->blue->off();
    this->green->off();
    this->red->on();
};


void RGBLed::singleGreen(){
    this->blue->off();
    this->green->on();
    this->red->off();
};


void RGBLed::singleBlue(){
    this->blue->on();
    this->green->off();
    this->red->off();
};
 

void RGBLed::off(){
    this->blue->off();
    this->green->off();
    this->red->off();
};
