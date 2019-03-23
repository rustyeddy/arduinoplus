// -*- c-mode -*-

#include <SR04.h>

#define TRIG_PIN 12
#define ECHO_PIN 11
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long dist;

char buffer[8];

void setupDistance() {
   Serial.begin(9600);
   delay(1000);
   buffer[0] = 'c';
   buffer[1] = 'm';
   buffer[2] = ':';
   buffer[3] = 0;
}

void sendDistance() {
  //a = sr04.DistanceAvg(10, 5);
  dist = sr04.Distance();
 
  Serial.print(buffer);
  Serial.println(dist);
}

void loopDistance() {
  sendDistance();
  delay(100);
}

