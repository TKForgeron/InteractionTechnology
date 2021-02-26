#include <Arduino.h>
#include "../BinaryActuator.h"
#include "Mosfet.h"

Mosfet::Mosfet(int pinNumber) : BinaryActuator(pinNumber){
};