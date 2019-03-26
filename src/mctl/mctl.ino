// Mobile Robot I/O 2019-03-04

#include "joystick.h"
#include "distance.h"

// Configurable variables
int delay_time = 100;

Joystick *joy = new Joystick();
Distance *dist;

void setup() {
  Serial.begin(9600);
  if (joy != 0) {
    joy->ReportChanges(1);
  }
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
  delay(delay_time);
}
