#ifndef _JOYSTICK_H_
#define _JOYSTICK_H_

class Joystick {
public:
  int pinX, pinY, pinSW;
  int x, y, sw;

  Joystick(int px, int py, int psw);
  void Report();
};


#endif // _JOYSTICK_H_
