// -*- c-mode -*-

#include <SR04.h>
#include "distance.h"

#define TRIG_PIN 12
#define ECHO_PIN 11
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long dist;

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
  dist = sr04.Distance();
  
}

void sendDistance() {
 
  Serial.print(buffer);
  Serial.println(dist);
}

void loopDistance() {
  sendDistance();
  delay(100);
}

