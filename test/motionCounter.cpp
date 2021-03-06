#include <Arduino.h>

int ledPin = 13;    // choose the pin for the LED
int inputPin = 6;   // choose the input pin (for PIR sensor)
int pirState = LOW; // we start, assuming no motion detected
int val = 0;        // variable for reading the pin status
int counter = 0;
int currentState = 0;
int previousState = 0;

void setup() {
  pinMode(ledPin, OUTPUT);  // declare LED as output
  pinMode(inputPin, INPUT); // declare sensor as input
  Serial.begin(9600);
}

void loop(){
  val = digitalRead(inputPin); // read input value

  if (val == HIGH) { // check if the input is HIGH
    digitalWrite(ledPin, HIGH); // turn LED ON
    
    if (pirState == LOW) {
      // we have just turned on
      currentState = 1;
      // We only want to print on the output change, not state
      pirState = HIGH;
      delay(1000);
    }
  } else {
    digitalWrite(ledPin, LOW); // turn LED OFF
    
    if (pirState == HIGH){
      // we have just turned of
      currentState = 0;
      // We only want to print on the output change, not state
      pirState = LOW;
    }
  }
  
  if(currentState != previousState){
    
    if(currentState == 1){
      counter = counter + 1;
      Serial.println(counter);
    }
  }
}