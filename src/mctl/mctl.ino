// Mobile Robot I/O 2019-03-04

#include "joystick.h"
#include "distance.h"

Joystick *joy;
Distance *dist;

void setup() {
  joy = new Joystick(X_pin, Y_pin, SW_pin);
  //dist = new Distance(TRIG_PIN, ECHO_PIN);
  Serial.begin(9600);
}

void loop() {
  joy->Report();
  //dist->Report();
  delay(100);
}
