#include <Arduino.h>
#include "Led/Led.h"
#include "Led/RGBLed.h"

Led internalLed(13); // maak internalLed object van de class "Led" met als argument meegegeven "13"
Led externalLed(12); // constructor is een methode, die tevens een nieuwe instantie van een class construct
Led greenLed(5); // bij het aanmaken van een class
Led blueLed(6); // het is eigenlijk dit: Led blueLed = new Led(1);
Led redLed(3);
RGBLed rgbLed(&redLed,&greenLed,&blueLed);

// pin assignments
 const int ldr = 0;
 const int motionSensor = 2;

 void setup() {
   pinMode(ldr, INPUT);
   pinMode(motionSensor, INPUT);
   Serial.begin(9600);
 }

 void loop() {
   int threshold = 500;
   int ldrVal = analogRead(ldr);
   bool motionDetected = digitalRead(motionSensor);

   if (ldrVal > threshold) {
     redLed.off();
     internalLed.on();
   } else{
     redLed.on();
     internalLed.off();
   }

   if (motionDetected) {
     externalLed.on();
   } else {
     externalLed.off();
   }

 }
