#include <SR04.h>
#include "tlv.h"

#define TRIG_PIN 12
#define ECHO_PIN 11
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long a;

TLV tlv = TLV();

void setup() {
   Serial.begin(115200);
   delay(1000);
}

void loop() {
  //a = sr04.DistanceAvg(10, 5);
  a = sr04.Distance();
  Serial.print(a);
  Serial.println("cm");
  delay(100);
}
