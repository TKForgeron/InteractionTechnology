#include <Arduino.h>
#include "Led/Led.h"
#include "Led/RGBLed.h"
#include "Timer/Timer.h"
#include "LightSensor/LightSensor.h"

Led internalLed(13); // maak internalLed object van de class "Led" met als argument meegegeven "13"
Timer ledTimer;
Led externalLed(12); // constructor is een methode, die tevens een nieuwe instantie van een class construct
Led greenLed(5); // bij het aanmaken van een class
Led blueLed(6); // het is eigenlijk dit: Led blueLed = new Led(1);
Led redLed(3);
RGBLed rgbLed(&redLed,&greenLed,&blueLed);
LightSensor lightSensor(0);

// pin assignments
 const int motionSensor = 2;

 void setup() {
   pinMode(motionSensor, INPUT);
   Serial.begin(9600);
   ledTimer.start(1000);
 }

 void loop() {
   bool motionDetected = digitalRead(motionSensor);

   if (lightSensor.activateCondition(500)) {
     redLed.off();
   } else{
     redLed.on();
   }

   if (motionDetected) {
     externalLed.on();
   } else {
     externalLed.off();
   }

   if (ledTimer.hasExpired()){
     ledTimer.repeat();
     internalLed.toggle();
   }
   
 }
