#include <Arduino.h>
#include <NewPing.h>
#include <LiquidCrystal.h>
#include "Timer/Timer.h"
#include "Actuator/BinaryActuator/Led/Led.h"
#include "Actuator/BinaryActuator/Mosfet/Mosfet.h"
#include "Sensor/BinarySwitch/BinarySwitch.h"
#include "Sensor/LightSensor/LightSensor.h"
#include "Sensor/MotionSensor/MotionSensor.h"
#include "Freshener/Freshener.h"
#include "Stopwatch/Stopwatch.h"

int i=0;
Timer timer;
Timer triggerDelay;
Stopwatch stopwatch;
BinarySwitch pushButton(7);
MotionSensor motionSensor(6);
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int trigPin = 9;    // Trigger
int echoPin = 8;    // Echo
unsigned long cm;   // Distance
NewPing distanceSensor(trigPin,echoPin,500);
Freshener freshener;
LightSensor lightSensor(0);
State state;
// MotionSensor motionSensor(10);

unsigned const int timeInUseThreshold = 60;
unsigned const int timesPulledThreshold = 5;

void setup() {
  //Serial Port begin
  Serial.begin(9600);
  //Define inputs and outputs
  timer.start(100);
  lcd.begin(16,2);

}
 
void loop() {
  state = freshener.getState();
  if (timer.hasExpired()) {
    timer.repeat();
    lcd.setCursor(0,1);
    lcd.print(state);
  }
  
  if (state == notInUse) {
    lcd.setCursor(0,0);
    lcd.print(F("Toilet not in use"));

    if (lightSensor.thresholdReached())
    {
      freshener.setState(inUse);
    }

  } else if (state == inUse) {

    if (motionSensor.getState() == HIGH) {
      i++;
      freshener.timesPulled += round(i/500);
    }
    Serial.println(freshener.timesPulled);
    
    // Serial.println("test");
    stopwatch.start();

    lcd.setCursor(0,0);
    lcd.print(F("Toilet in use"));
    
    if (!lightSensor.thresholdReached()) {  // lightIsOff
        Serial.println("setting state to triggered");
        freshener.setState(triggered);
    }
    
  } else if (state == triggered) {

    stopwatch.stop();
    freshener.timeInUse = stopwatch.getTime();
    stopwatch.reset();

    Serial.println(freshener.timeInUse);
    

    if (freshener.timesPulled >= timesPulledThreshold && freshener.timeInUse >= timeInUseThreshold) {  // number 2
      // freshener.spray(2);
      lcd.setCursor(0,0);
      lcd.print(F("Number two detected"));
    } else if (freshener.timeInUse >= timeInUseThreshold && freshener.timesPulled >= timesPulledThreshold) {  // cleaning
      lcd.setCursor(0,0);
      lcd.print(F("you're cleaning"));
    } else if (freshener.timeInUse < timeInUseThreshold) {  // number 1
      // freshener.spray(1);
      lcd.setCursor(0,0);
      lcd.print(F("Number one detected"));
    } else {  // cannot recognise
      lcd.setCursor(0,0);
      lcd.print(F("you're a mysterious toilet visitor"));
    }

    delay(5000);
    freshener.reset();
  }
}