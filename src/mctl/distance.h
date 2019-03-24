#ifndef _DISTANCE_H_
#define _DISTANCE_H_

#define TRIG_PIN 12
#define ECHO_PIN 11

class Distance {
public:
  int pinT, pinE;

  Distance(int pt, int pe);
  void Report();
};


#endif // _DISTANCE_H_
