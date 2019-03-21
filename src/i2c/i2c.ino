#include <Wire.h>

<<<<<<< HEAD
#define SLAVE_ADDRESS 0x12
=======
#define SLAVE_ADDRESS 0x04


>>>>>>> 7c3b937b748f4fe59cc75dae7d0645d9edee74dd
int number = 0;
int state  = 0;

void receiveData(int byteCount);
void sendData();

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  Serial.begin(9600); // make sure this is not too fast for other sensors

  // init i2c as slave 
  Wire.begin(SLAVE_ADDRESS);

  // Hookup our callbacks
  Wire.onReceive(receiveData);
  Wire.onRequest(sendData);
  Serial.println("Ready!");
}

void loop() {
  Serial.println("top of loop");
  // The loop is not used since i2c is driven by interrupts
  delay(1000); // stop us from having a spinning loop.
  digitalWrite(13, LOW);
}

void receiveData(int byteCount) {

  Serial.print("receive data ");
  Serial.println(byteCount);
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
