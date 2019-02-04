#include <I2Cdev.h>
#include "TBMotor.h"

OseppTBMotor M1(12, 11);
OseppTBMotor M2(8, 3); 

int dir = 1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  Serial.println("Begging loop");
  // put your main code here, to run repeatedly:
  if (dir) {  
    M1.backward(100);
    M2.backward(100);
  } else {
    M1.forward(100);
    M2.forward(120);
  }
  delay(4000);
  dir = !dir ;
}
