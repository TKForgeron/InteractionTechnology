#include "Arduino.h"
#include "classes.h"
// Class          Object
LED_Controls      LED;

const int ledR = 3;
const int ledG = 5;
const int ledB = 6;
const int ledOther = 13;

void setup() {
  LED.Begin(ledOther);
  LED.Begin(ledR);
  LED.Begin(ledG);
  LED.Begin(ledB);
}

void loop() {
  // RED blink
  LED.On(ledR);
  delay(500);
  LED.Off(ledR);
  delay(500);
  // GREEN blink
  LED.On(ledG);
  delay(500);
  LED.Off(ledG);
  delay(500);
  // BLUE blink
  LED.On(ledB);
  delay(500);
  LED.Off(ledB);
  delay(500);

  // YELLOW blink
  LED.On(ledR);
  LED.On(ledG);
  delay(500);
  LED.Off(ledR);
  LED.Off(ledG);
  delay(500);
  // CYAN blink
  LED.On(ledG);
  LED.On(ledB);
  delay(500);
  LED.Off(ledG);
  LED.Off(ledB);
  delay(500);
  // MAGENTA blink
  LED.On(ledB);
  LED.On(ledR);
  delay(500);
  LED.Off(ledB);
  LED.Off(ledR);
  delay(500);

  LED.On(ledOther);
  // WHITE pause
  LED.On(ledR);
  LED.On(ledG);
  LED.On(ledB);
  delay(1000);
  LED.Off(ledR);
  LED.Off(ledG);
  LED.Off(ledB);
  LED.Off(ledOther);
  delay(1000);

}
