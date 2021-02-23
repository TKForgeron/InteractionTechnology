#include <Arduino.h>
#include "Timer/Timer.h"
#include "Led/Led.h"
#include "BinarySwitch/BinarySwitch.h"
#include "LightSensor/LightSensor.h"

Timer timer;
Led internalLed(13);
BinarySwitch pushButton(12);
LightSensor lightSensor(0);
 

void setup() {
  //Serial Port begin
  Serial.begin(9600);
  //Define inputs and outputs
  timer.start(50);
}
 
void loop() {
  // if(lightSensor.thresholdReached()){
  //   internalLed.toggle();
  //   Serial.println("threshold reached");
  // }else{
  //   Serial.println("threshold not reached");
  // }
  // Serial.print("initialValue: ");
  // Serial.println(lightSensor.initialValue);
  // delay(500);

  if (pushButton.getState()){
    if(!pushButton.hasMillis()){
      pushButton.setBeginMillis(millis());
    }
  }
  else{
    Serial.println(pushButton.getPressedTime(millis()));
    pushButton.stopTimer();
  }
  delay(1000);
}
