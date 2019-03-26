#include <Arduino.h>
#include "joystick.h"

Joystick::Joystick() {}
Joystick::Joystick(int x, int y, int sw) {
  Setup(x, y, sw);
}

void Joystick::ReportChanges(int yes) {
  report_changes = yes;
}

void
Joystick::Setup(int x, int y, int sw) {
  pinX = x;
  pinY = y;
  pinSW = sw;

  // The last numbers
  lastX = lastY = 0;
  lastSW = 77; // a nonsense number forcing it to be reset
  pinMode(pinSW, INPUT);
  digitalWrite(pinSW, HIGH);
  ReportChanges(0);
};

/*
 * Joystick report will send a packet either everytime it is asked,
 * or it will only send a packet when something has changed, depending
 * on the report_changes flag.
 */
void
Joystick::Report() {
  int sw = digitalRead(pinSW);
  int x = analogRead(pinX);
  int y = analogRead(pinY);

  // Report changes is broken!
  if (report_changes == 1) {
    if (lastSW == sw && lastX == x && lastY == y) {
      goto finished;
    }
    int dx = x - lastX;
    int dy = y - lastY;
    int dsw = lastSW - sw;

    Serial.print("jd:"); Serial.print(dsw);
    Serial.print(":"); Serial.print(dx);
    Serial.print(":"); Serial.println(dy);
  } else {
    Serial.print("jc:"); Serial.print(sw);
    Serial.print(":"); Serial.print(x);
    Serial.print(":"); Serial.println(y);
  }

 finished:
  lastX = x;
  lastY = y;
  lastSW = sw;
}
