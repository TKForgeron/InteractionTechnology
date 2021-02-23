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
BinarySwitch pushButton(8);
 
void setup() {
  //Serial Port begin
  Serial.begin (9600);
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  timer.start(50);
}
 
void loop() {
  if (timer.hasExpired()){
    timer.repeat();
    digitalWrite(trigPin, LOW);
    delayMicroseconds(5);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
  
    duration = pulseIn(echoPin, HIGH);
    distance = duration / 2 * 0.0343;
    
    Serial.print(F("Distance: "));
    Serial.println(distance);
  }else{
    internalLed.toggle();
  }  
  
}
