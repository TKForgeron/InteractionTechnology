#include <Arduino.h>
#include "BinarySwitch/BinarySwitch.h"

BinarySwitch::BinarySwitch(int pinNumber) { 
    // Set attribute pinNumber to value passed to constructor
    this->pinNumber = pinNumber;
    // Set up for BinarySwitch use
    pinMode(pinNumber,INPUT);
};

// Methods
bool BinarySwitch::getState(){
    this->buttonState = !digitalRead(this->pinNumber);
    return this->buttonState;
}

void BinarySwitch::updateState() {
  // the button has been just pressed
  if (this->buttonState == HIGH) {
      this->startPressed = millis();
      this->idleTime = this->startPressed - this->endPressed;
  } else {  // the button has been just released
      this->endPressed = millis();
      this->holdTime = this->endPressed - this->startPressed;
  }
}

/* Records time button is idle/on hold WHILE button is still pressed/released
   usage: to do stuff WHILE button is still being pressed (e.g. showing 'live' timePressed on LCD)*/
void BinarySwitch::updateCounter() {
  // the button is still pressed
  if (this->buttonState == HIGH) {
      this->holdTime = millis() - this->startPressed;
  } else {  // the button is still released
      this->idleTime = millis() - endPressed;
  }
}