#include <Arduino.h>
#include "joystick.h"

Joystick::Joystick(int px, int py, int psw) {
  pinX = px;
  pinY = py;
  pinSW = psw;
  pinMode(pinSW, INPUT);
  digitalWrite(pinSW, HIGH);
}

void Joystick::Report() {
  int sw = digitalRead(pinSW);
  int x = analogRead(pinX);
  int y = analogRead(pinY);
  Serial.print("j:"); Serial.print(sw);
  Serial.print(":"); Serial.print(x);
  Serial.print(":"); Serial.println(y);
}
