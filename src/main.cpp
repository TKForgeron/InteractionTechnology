#include <Arduino.h>
#include "Timer/Timer.h"
#include "Actuator/BinaryActuator/Led/Led.h"
#include "Actuator/BinaryActuator/Mosfet/Mosfet.h"
#include "Sensor/BinarySwitch/BinarySwitch.h"
#include "Sensor/LightSensor/LightSensor.h"

Timer timer;
Led internalLed(13);
Led externalLed(7);
Mosfet freshenerSwitch(3);
BinarySwitch pushButton(12);
LightSensor lightSensor(0);

void setup() {
  //Serial Port begin
  Serial.begin(9600);
  //Define inputs and outputs
  timer.start(500);
}
 
void loop() {
  pushButton.buttonState = pushButton.getState();

  // Versie 1 - als je dingen wil doen als reactie op (de tijd van) de ingedrukte knop
  if (pushButton.buttonState != pushButton.lastButtonState) { // button state changed
     pushButton.updateState();
  }

  // Versie 2 - als je dingen wil doen tijdens indrukken van knop
  // if (pushButton.buttonState != pushButton.lastButtonState) { 
  //    pushButton.updateState(); // button state changed. It runs only once.
  // } else {
  //    pushButton.updateCounter(); // button state not changed. It runs in a loop.
  // }

  if (timer.hasExpired()){
    timer.repeat();
    Serial.print("idle: ");
    Serial.println(pushButton.idleTime);
    Serial.print("hold: ");
    Serial.println(pushButton.holdTime);
    Serial.println(" ");
  }

  pushButton.lastButtonState = pushButton.buttonState;  // save state for next loop
}
