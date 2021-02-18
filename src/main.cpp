// Imported Libraries
#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// Homemade Libraries
#include "Led/Led.h"
#include "Led/RGBLed.h"
#include "Timer/Timer.h"
#include "LightSensor/LightSensor.h"


Timer ledTimer;
Timer tempTimer;
Led internalLed(13);                        // maak internalLed object van de class "Led" met als argument meegegeven "13"
Led externalLed(12);                        // constructor is een methode, die tevens een nieuwe instantie van een class construct
Led greenLed(5);                            // bij het aanmaken van een class
Led blueLed(6);                             // het is eigenlijk dit: Led blueLed = new Led(1);
Led redLed(3);
RGBLed rgbLed(&redLed,&greenLed,&blueLed);  // create rgbLed instance that is composed of 3 led instances
LightSensor lightSensor(0);
OneWire oneWire(8);                         // create one-wire instance for pin8
DallasTemperature tempSensor(&oneWire);     // create tempSensor object using the oneWire(8) object/instance

// Variables
float temp = 0;
// Constants
const int motionSensor = 2;

 void setup() {
   Serial.begin(9600);
   pinMode(motionSensor, INPUT);
   ledTimer.start(2500);
   tempTimer.start(1000);
   tempSensor.begin();
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
   
   if (tempTimer.hasExpired()){
     tempTimer.repeat();
     tempSensor.requestTemperatures();
     temp = tempSensor.getTempCByIndex(0);
     Serial.print(F("Current temperature: "));
     Serial.println(temp);
   }

 }
