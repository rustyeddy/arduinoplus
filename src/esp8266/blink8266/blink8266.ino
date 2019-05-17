/*
  ESP8266 Blink by Simon Peter
  Blink the blue LED on the ESP-01 module
  This example code is in the public domain

  The blue LED on the ESP-01 module is connected to GPIO1
  (which is also the TXD pin; so we cannot use Serial.print() at the same time)

  Note that this sketch uses LED_BUILTIN to find the pin with the internal LED
*/

#include "LED.h"

//int pin = LED_BUILTIN;
int greenLed = 1;
int redLed = 2;

LED *red, *green;

void setup() {
  red = new LED(redLed, HIGH);
  green = new LED(greenLed, LOW);
}

// the loop function runs over and over again forever
void loop() {
  red->On();
  green->Off();
  delay(200);

  red->Off();
  green->Off();
  delay(300);

  red->Off();
  green->On();
  delay(500);                      // Wait for two seconds (to demonstrate the active low LED)

  red->Off();
  green->Off();
  delay(100);
}
