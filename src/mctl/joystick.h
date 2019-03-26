#ifndef _JOYSTICK_H_
#define _JOYSTICK_H_

class Joystick {
private:
  int active = 0;
  int pinX = 0;
  int pinY = 1;
  int pinSW = 2;

public:
  Joystick() {
  }

  Joystick(int x, int y, int sw) {
    Setup(x, y, sw);
  }
  void Setup(int x, int y, int sw) {
    pinX = x;
    pinY = y;
    pinSW = sw;
    pinMode(pinSW, INPUT);
    digitalWrite(pinSW, HIGH);
  };
  
  void Report() {
    int sw = digitalRead(pinSW);
    int x = analogRead(pinX);
    int y = analogRead(pinY);
    Serial.print("j:"); Serial.print(sw);
    Serial.print(":"); Serial.print(x);
    Serial.print(":"); Serial.println(y);
  }
};


#endif // _JOYSTICK_H_
