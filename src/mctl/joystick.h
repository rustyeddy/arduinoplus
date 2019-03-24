#ifndef _JOYSTICK_H_
#define _JOYSTICK_H_

// Arduino pin numbers
const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = 0; // analog pin connected to X output
const int Y_pin = 1; // analog pin connected to Y output

class Joystick {
public:
  int pinX, pinY, pinSW;
  int x, y, sw;

  Joystick(int px, int py, int psw);
  void Report();
};


#endif // _JOYSTICK_H_
