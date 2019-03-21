#include <SR04.h>
#define TRIG_PIN 12
#define ECHO_PIN 11
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long a;

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

// -----------------------------------------
// TLV
// -----------------------------------------
#define MAX_DATA 16

class TLV
{
public:
    byte type;
    byte len;
    char buffer[MAX_DATA];

    TLV *Get();
    int Send(char *buf);
};
