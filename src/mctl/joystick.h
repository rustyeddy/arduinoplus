#ifndef _JOYSTICK_H_
#define _JOYSTICK_H_

class Joystick {
private:
    int active = 0;
    int _pinX,_pinY, _pinSW;	// active pins
    int _lastX, lastY, lastSW;	// last values 

public:
    int ReportChanges = 0;
    Joystick();
    Joystick(int x, int y, int sw);
    void Setup(int x, int y, int sw);
};

#endif // _JOYSTICK_H_
