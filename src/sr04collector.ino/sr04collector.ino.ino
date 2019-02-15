#include "SR04.h"
#include "SimpleDHT.h"

#define TRIG_PIN 12
#define ECHO_PIN 11
SR04 sr04 = SR04(ECHO_PIN, TRIG_PIN);
long a;

int pinDHT = 2;
SimpleDHT11 dht;

void setup() {
  Serial.begin(9600);
  delay(1000);
}

int lcount = 0;
int temploop = 0;
int tempincr = 10;
void loop() {
  Serial.println("beg: ~~~~~~~~~ ");
  byte temp = 0;
  byte hum = 0;
  byte data[40] = {0};

  
  // Only collect temprature changes every 100 loops
  if (lcount == temploop) {
    if (dht.read(pinDHT, &temp, &hum, data)) {
      Serial.print("err: tmp\n");
      temploop += tempincr;
    } else {
      /*
        for (int i = 0; i < 40; i++) {
        Serial.print((int)data[i]);
        if (i > 0 && ((i + 1) % 4) == 0) {
          Serial.print(' ');
        }
        }
      */
      Serial.print("tmp: "); Serial.print((int)temp); Serial.println("C ");
      Serial.print("hum: "); Serial.print((int)hum); Serial.println("%");
    }
    temploop += tempincr;
  }
  lcount++;

  a = sr04.Distance();
  Serial.print("dist: "); Serial.print(a); Serial.println("");
  
  delay(500);
}
