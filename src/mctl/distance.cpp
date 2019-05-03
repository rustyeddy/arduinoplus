// -*- c-mode -*-

#include "distance.h"

#include <SR04.h>

SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);


char buffer[8];

void setupDistance() {
   buffer[0] = 'c';
   buffer[1] = 'm';
   buffer[2] = ':';
   buffer[3] = 0;
}

Distance::Distance(int trig, int echo) {
  pinT = trig;
  pinE = echo;
}

void Distance::Report() {
  //a = sr04.DistanceAvg(10, 5);
  long cm = sr04.Distance();
  
  Serial.print("cm:");
  Serial.println(cm);
}
