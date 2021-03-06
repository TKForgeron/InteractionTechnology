#include <Arduino.h>
#include <NewPing.h>
#include <LiquidCrystal.h>
#include <DallasTemperature.h>
#include "Timer/Timer.h"
#include "Actuator/BinaryActuator/Led/Led.h"
#include "Actuator/BinaryActuator/Freshener/Freshener.h"
#include "Sensor/BinarySwitch/BinarySwitch.h"
#include "Sensor/LightSensor/LightSensor.h"
#include "Sensor/MotionSensor/MotionSensor.h"
#include "Stopwatch/Stopwatch.h"


// Timers & Stopwatches

Timer timer;
Timer triggerDelay;
Timer toiletUseDisplayTimer;
Stopwatch stopwatch;

// LCD
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Actuators
Freshener freshener(10);

// Sensors
MotionSensor motionSensor(6);
LightSensor lightSensor(0);
DallasTemperature temperatureSensor;

// Classification Properties
State state;
const unsigned long timeInUseThreshold = 10;
const unsigned long timesPulledThreshold = 5;

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);

}
 
void loop() {
  state = freshener.getState();

  temperatureSensor.getTempC();
  
  if (state == notInUse) {
    lcd.setCursor(0,0);
    lcd.print(F("Toilet not in use"));

    if (lightSensor.thresholdReached())
    {
      freshener.setState(inUse);
    }

  } else if (state == inUse) {

    freshener.timesPulled = motionSensor.motionCounter();
    
    stopwatch.start();

    lcd.setCursor(0,0);
    lcd.print(F("Toilet in use"));
    
    if (!lightSensor.thresholdReached()) {  // lightIsOff
        Serial.println("setting state to triggered");
        toiletUseDisplayTimer.start(5000);
        freshener.setState(triggered);
    }
    
  } else if (state == triggered) {

    stopwatch.stop();
    freshener.timeInUse = stopwatch.getTime();
    stopwatch.reset();
  
    lcd.setCursor(0,0);

    if (freshener.timesPulled >= timesPulledThreshold && freshener.timeInUse >= timeInUseThreshold) {  // number 2
      lcd.print(F("NUMBER TWO VISIT"));
      freshener.spray(2);
    } else if (freshener.timeInUse < timeInUseThreshold) {  // number 1      
      freshener.spray(1);
    } else if (freshener.timeInUse >= timeInUseThreshold && freshener.timesPulled >= timesPulledThreshold) {  // cleaning
      lcd.print(F("CLEANING"));
    } else {  // cannot recognise
      lcd.print(F("MYSTERIOUS VISIT"));
    }

    if (toiletUseDisplayTimer.hasExpired()) {
      freshener.reset();
      motionSensor.reset();
      toiletUseDisplayTimer.stop();
    }
  }
  
}