#include <Wire.h>

#define SLAVE_ADDRESS 0x04
int number = 0;
int state  = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  Serial.begin(115200); // make sure this is not too fast for other sensors

  // init i2c as slave 
  Wire.begin(SLAVE_ADDRESS);

  // Hookup our callbacks
  Wire.onReceive(receiveData);
  Wire.onRequest(sendData);
  Serial.println("Ready!");
}

void loop() {
  // The loop is not used since i2c is driven by interrupts
  delay(100); // stop us from having a spinning loop.
}

void receiveData(int byteCount) {
  while(Wire.available()) {
    number = Wire.read();
    Serial.print("data recieved ");
    Serial.println(number);

    if (state == 0) {
      digitalWrite(13, HIGH);  // set led on
      state = 1;
    } else {
      digitalWrite(13, LOW); // led off
      state = 0;
    }
  }
}
 
void sendData() {
  Wire.write(number);
}
