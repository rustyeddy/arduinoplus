#ifndef _JOYSTICK_H_
#define _JOYSTICK_H_

class Joystick {
private:
  int active = 0;
  int pinX = 0;
  int pinY = 1;
  int pinSW = 2;
  int lastX, lastY, lastSW;
  int report_changes = 0;

public:
  Joystick();
  Joystick(int x, int y, int sw);

  void Setup(int x, int y, int sw);
  void ReportChanges(int yes);
  void Report();
};


#endif // _JOYSTICK_H_
