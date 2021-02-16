#include <millisDelay.h>

int led = 13;
// Pin 13 has an LED connected on most Arduino boards.
bool ledOn = false; // keep track of the led state
millisDelay ledDelay;

void setup() {
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);   // initialize the digital pin as an output.
  digitalWrite(led, LOW); // turn led off
  ledOn = false;
  // start delay
  ledDelay.start(1500);
}

void loop() {
  // check if delay has timed out
  if (ledDelay.justFinished()) {
    ledDelay.repeat(); // start delay again without drift
    // toggle the led
    ledOn = !ledOn;
    if (ledOn) {
      digitalWrite(led, HIGH); // turn led on
    } else {
      digitalWrite(led, LOW); // turn led off
    }
  }
}