#include "Arduino.h"
#include "Hardware/Led/Led.h"

Led internalLed(13);
Led externalLed(12);
Led greenLed(5);
Led blueLed(6);
Led redLed(3);

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
