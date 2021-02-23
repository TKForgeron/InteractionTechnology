#include <Arduino.h>
#include "BinarySwitch/BinarySwitch.h"

BinarySwitch::BinarySwitch(int pinNumber) { 
    // Set attribute pinNumber to value passed to constructor
    this->pinNumber = pinNumber;
    // Set up for LightSensor use
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

      if (this->idleTime >= 500 && this->idleTime < 1000) {
          Serial.println("Button was idle for half a second");
      }

      if (this->idleTime >= 1000) {
          Serial.println("Button was idle for one second or more"); 
      }

  // the button has been just released
  } else {
      this->endPressed = millis();
      this->holdTime = this->endPressed - this->startPressed;

      if (this->holdTime >= 500 && this->holdTime < 1000) {
          Serial.println("Button was hold for half a second"); 
      }

      if (this->holdTime >= 1000) {
          Serial.println("Button was hold for one second or more"); 
      }

  }
}

void BinarySwitch::updateCounter() {
  // the button is still pressed
  if (this->buttonState == HIGH) {
      this->holdTime = millis() - this->startPressed;

      if (this->holdTime >= 1000) {
          Serial.println("Button is hold for more than a second"); 
      }

  // the button is still released
  } else {
      this->idleTime = millis() - endPressed;

      if (this->idleTime >= 1000) {
          Serial.println("Button is released for more than a second");  
      }
  }
}