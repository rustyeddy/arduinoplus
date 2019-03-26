// Mobile Robot I/O 2019-03-04

#include "joystick.h"
#include "distance.h"

Joystick *joy;
Distance *dist;

void setup() {
  Serial.begin(9600);
}

void loop() {

  if (dist == NULL && joy == NULL) {
    Serial.println("nothing to do, wait for a config change");
  }
  if (dist != NULL) {
    dist->Report();
  }
  if (joy != NULL) {
    joy->Report();
  }
  delay(2000);
}
