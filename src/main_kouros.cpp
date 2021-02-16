#include <Arduino.h>
#include "Led/Led.h"
#include "Led/RGBLed.h"

Led redLed(3);
Led blueLed(5);
Led greenLed(6);
RGBLed rgbLed(&redLed,&greenLed,&blueLed);

void setup() {

};

void loop() {
    
};