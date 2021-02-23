#include <Arduino.h>
#include "Timer/Timer.h"
#include "Led/Led.h"
#include "BinarySwitch/BinarySwitch.h"

const int trigPin = 11;    // Trigger
const int echoPin = 12;    // Echo
long duration;
int distance;
Timer timer;
Led internalLed(13);
BinarySwitch pushButton(12);
 
void setup() {
  //Serial Port begin
  Serial.begin (9600);
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  timer.start(50);
}
 
void loop() {
  if (pushButton.getState()){
    if(!pushButton.hasMillis()){
      pushButton.setBeginMillis(millis());
    }
  }
  else{
    Serial.println(pushButton.getPressedTime());
  }
}
