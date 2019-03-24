//www.elegoo.com
//2016.12.09

#include "joystick.h"

Joystick *joy;

// Arduino pin numbers
const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = 0; // analog pin connected to X output
const int Y_pin = 1; // analog pin connected to Y output

void setup() {
  joy = new Joystick(X_pin, Y_pin, SW_pin);
  Serial.begin(9600);
}

void loop() {
  joy->Report();
  delay(100);
}
