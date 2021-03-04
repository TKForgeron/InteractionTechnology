#include <Arduino.h>
#include "Stopwatch.h"

Stopwatch::Stopwatch(){
    // Initializing object
    this->startTime = 0;
    this->stopTime = 0;
    this->isCounting = false;
}

void Stopwatch::start(){

    if(!this->isCounting){
        this->startTime = millis();
        this->isCounting = true;
    }
   
}

void Stopwatch::stop(){

   if(this->isCounting){
        this->stopTime = millis();
        this->isCounting = false;
    }
}

unsigned int Stopwatch::getTime(){
    unsigned int elapsedTime;
    if(this->isCounting){
        elapsedTime = millis() - this->startTime;
    } else {
        elapsedTime = this->stopTime - this->startTime;
    }

    return elapsedTime / 1000;
}

void Stopwatch::reset(){
    this->startTime = 0;
    this->stopTime = 0;
    this->isCounting = false;
}
