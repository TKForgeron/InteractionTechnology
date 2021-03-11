#include <Arduino.h>
// #include <NewPing.h>
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
Timer timer;
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
const unsigned long timeInUseThresholdLow = 10;
const unsigned long timeInUseThresholdHigh = 120;
const unsigned long timesPulledThresholdLow = 5;
const unsigned long timesPulledThresholdHigh = 20;


// Globals
const int spraysLeftStartingAddress = 0;
int sprayAmount;
unsigned long spraysLeftLong;



void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  freshener.spraysLeft = EEPROM.get(spraysLeftStartingAddress, spraysLeftLong);
  timer.start(1000);

}
 
void loop() {

  state = freshener.getState();

  if(state == menu){

    rgbled.singleBlue();

    lcd.setCursor(10,1);
    lcd.print(freshener.manualSprayDelay);

    // BUTTON 1: If button is held longer than 1 second go to not in use, else reset sprays
    resetSpraysButton.buttonState = resetSpraysButton.getState();
    if(resetSpraysButton.buttonState != resetSpraysButton.lastButtonState){
      resetSpraysButton.updateState();
      if (resetSpraysButton.holdTime>=1000){
        freshener.setState(inUse);
      } else {
        freshener.spraysLeft=2400;
        EEPROM.put(spraysLeftStartingAddress, freshener.spraysLeft);

      } 
      
    }

    resetSpraysButton.lastButtonState = resetSpraysButton.buttonState;

    // BUTTON 2: Changing delay
    if (changeDelayButton.getState()){
          if (millis() > changeDelayButton.lastPressed + 2000){
            if(freshener.manualSprayDelay == low){
              freshener.manualSprayDelay = medium;
            } else if (freshener.manualSprayDelay == medium) {
              freshener.manualSprayDelay = high;
            } else {
              freshener.manualSprayDelay = low;
            }
          changeDelayButton.lastPressed = millis();
          }
    } 

    //Button 3: Manual spray
    if(manualSprayButton.getState()){
      if (millis() > changeDelayButton.lastPressed + 2000){
        freshener.spray(1);
        freshener.spraysLeft-=1;
        EEPROM.put(spraysLeftStartingAddress, freshener.spraysLeft);
      }
    }    

  } else {

    // Switch to menu state
    if(resetSpraysButton.getState() && millis() > changeDelayButton.lastPressed + 2000){
      lcd.print(F(" "));
      freshener.setState(menu);
    }

    lcd.setCursor(0,0);
    lcd.print("Sprays: ");
    lcd.setCursor(9,0);
    lcd.print(freshener.spraysLeft);

    lcd.setCursor(0,1);
    sensors.requestTemperatures();
    lcd.print(sensors.getTempCByIndex(0));
    lcd.setCursor(5,1);
    lcd.print("C");

    // Toilet is not in use
    if (state == notInUse) {

      rgbled.yellow();

      if (lightSensor.thresholdReached()){
        freshener.setState(inUse);
      }

    } else if (state == inUse) {

      rgbled.magenta();

      freshener.timesPulled = motionSensor.motionCounter();
      
      stopwatch.start();
      
      if (!lightSensor.thresholdReached()) {
          toiletUseDisplayTimer.start(5000);
          freshener.setState(triggered);
      }
      
    } else if (state == triggered) {

      rgbled.cyan();

      stopwatch.stop();
      freshener.timeInUse = stopwatch.getTime();
      stopwatch.reset();

      Serial.println(freshener.timeInUse);
      Serial.println(freshener.timesPulled);

    
    
      if (freshener.timesPulled >= timesPulledThresholdLow && freshener.timesPulled <= timesPulledThresholdHigh && freshener.timeInUse >= timeInUseThresholdHigh) {  // Number 2
        rgbled.white();
        sprayAmount = 2;
      } else if (freshener.timesPulled < timesPulledThresholdLow && freshener.timeInUse >= timeInUseThresholdLow) {  // Number 1
        rgbled.singleRed();
        sprayAmount = 1;  
      } else if (freshener.timesPulled > timesPulledThresholdHigh) {  // Cleaning
        rgbled.singleGreen();
        sprayAmount = 0;
      } else {  // Can not recognise
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

  if(timer.hasExpired()){
    Serial.println(freshener.timeInUse);
    Serial.println(freshener.timesPulled);
    Serial.println(freshener.spraysLeft);
    Serial.println(lightSensor.getValue());
    timer.repeat();
    
  }
  
}