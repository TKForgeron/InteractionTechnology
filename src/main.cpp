#include <Arduino.h>
#include <LiquidCrystal.h>
#include <OneWire.h>
#include <EEPROM.h>
#include <DallasTemperature.h>
#include "Timer/Timer.h"
#include "Actuator/BinaryActuator/Freshener/Freshener.h"
#include "Sensor/LightSensor/LightSensor.h"
#include "Sensor/MotionSensor/MotionSensor.h"
#include "Stopwatch/Stopwatch.h"
#include "Actuator/BinaryActuator/Led/RGBLed.h"
#include "Sensor/BinarySwitch/BinarySwitch.h"


// Timers & Stopwatches
Timer triggerDelay;
Timer toiletUseDisplayTimer;
Stopwatch stopwatch;

// LCD
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Actuators
Freshener freshener(10);
Led red(7);
Led green(8);
Led blue(9);

RGBLed rgbled(&red, &green, &blue);

// Sensors
MotionSensor motionSensor(6);
LightSensor lightSensor(A0);

BinarySwitch resetSpraysButton(A1);
BinarySwitch changeDelayButton(A2);
BinarySwitch manualSprayButton(A3);

OneWire oneWire(A4);
DallasTemperature sensors(&oneWire);


// Classification Properties
State state;
const unsigned long timeInUseThreshold = 10;
const unsigned long timesPulledThreshold = 5;


// Globals
const int spraysLeftStartingAddress = 0;
int sprayAmount;
unsigned long spraysLeftLong;



void setup() {
  lcd.begin(16,2);
  freshener.spraysLeft = EEPROM.get(spraysLeftStartingAddress, spraysLeftLong);
}
 
void loop() {
  

  state = freshener.getState();

  if(state == menu){

    rgbled.singleBlue();

    lcd.setCursor(0,0);
    lcd.print(freshener.manualSprayDelay);


    // In the menu state we can fire a manual spray after the set delay
    // if(manualSprayButton.getState()){
    //   delay(freshener.manualSprayDelay * 1000);
    //   freshener.spray(1);
    // }


    // // Switch to not in use if held longer than 2 seconds
    // if (changeDelayButton.getState() && resetSpraysButton.getState()){
    //   freshener.setState(notInUse);
    // }
    
    // if (resetSpraysButton.getState()) {
    //   freshener.spraysLeft=2400;
    //   EEPROM.put(spraysLeftStartingAddress, freshener.spraysLeft);
     
    // if (changeDelayButton.getState()){
    //       if (millis() > changeDelayButton.lastPressed + 2000){
    //         if(freshener.manualSprayDelay == low){
    //           freshener.manualSprayDelay = medium;
    //         } else if (freshener.manualSprayDelay == medium) {
    //           freshener.manualSprayDelay = high;
    //         } else {
    //           freshener.manualSprayDelay = low;
    //         }
    //       changeDelayButton.lastPressed = millis();
    //       }
    // }         
  } else {

    // Switch to menu state
    // if(resetSpraysButton.getState()){
    //   freshener.setState(menu);
    // }

    lcd.setCursor(0,0);
    lcd.print(freshener.spraysLeft);

    lcd.setCursor(1,0);
    sensors.requestTemperatures();
    lcd.print(sensors.getTempCByIndex(0));

    // Toilet is not in use
    if (state == notInUse) {

      rgbled.yellow();
      
      lcd.setCursor(0,0);
      lcd.print(F("Toilet not in use"));

      if (lightSensor.thresholdReached()){
        freshener.setState(inUse);
      }

    } else if (state == inUse) {

      rgbled.magenta();

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

      rgbled.cyan();

      stopwatch.stop();
      freshener.timeInUse = stopwatch.getTime();
      stopwatch.reset();
    
      lcd.setCursor(0,0);

      if (freshener.timesPulled >= timesPulledThreshold && freshener.timeInUse >= timeInUseThreshold) {  // number 2
        rgbled.white();
      } else if (freshener.timeInUse < timeInUseThreshold) {  // number 1 
        rgbled.singleRed();
        sprayAmount = 1;   
      } else if (freshener.timeInUse >= timeInUseThreshold && freshener.timesPulled >= timesPulledThreshold) {  // cleaning
        rgbled.singleGreen();
        sprayAmount = 0;
      } else {  // cannot recognise
        rgbled.off();
        sprayAmount = 0;
      }

      if (sprayAmount > 0){
        freshener.spray(sprayAmount);
        freshener.spraysLeft-=sprayAmount;
        EEPROM.put(spraysLeftStartingAddress, freshener.spraysLeft);
      }

      if (toiletUseDisplayTimer.hasExpired()) {
        freshener.reset();
        motionSensor.reset();
        toiletUseDisplayTimer.stop();
      }
    }

  }
  
}