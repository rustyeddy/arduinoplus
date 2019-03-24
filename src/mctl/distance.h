#ifndef _JOYSTICK_H_
#define _JOYSTICK_H_

class Distance {
public:
  int pinT, pinE;

  Distance(int pt, int pe);
  void Report();
};


#endif // _JOYSTICK_H_
