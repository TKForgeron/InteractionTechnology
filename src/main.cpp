#include <Arduino.h>
#include "Timer/Timer.h"
#include "Led/Led.h"
#include "BinarySwitch/BinarySwitch.h"
#include "LightSensor/LightSensor.h"

Timer timer;
Led internalLed(13);
Led externalLed(7);
BinarySwitch pushButton(12);
LightSensor lightSensor(0);
 

void setup() {
  //Serial Port begin
  Serial.begin(9600);
  //Define inputs and outputs
  timer.start(50);
}
 
void loop() {
  pushButton.buttonState = pushButton.getState();

  // Versie 1
  // if (pushButton.buttonState != pushButton.lastButtonState) { // button state changed
  //    pushButton.updateState();
  // }

  // Versie 2
  if (pushButton.buttonState != pushButton.lastButtonState) { 
     pushButton.updateState(); // button state changed. It runs only once.
  } else {
     pushButton.updateCounter(); // button state not changed. It runs in a loop.
  }

  pushButton.lastButtonState = pushButton.buttonState;        // save state for next loop
}
