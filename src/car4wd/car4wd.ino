
//include motor code
#include "TBMotor.h"

int s1 = 500;
int s2 = 500;
int s3 = 500;
int s4 = 500;

OseppTBMotor m1(12, 11); // these are SPI chips
OseppTBMotor m3(7, 6);

OseppTBMotor m2(8, 3);
OseppTBMotor m4(4, 5);

void setup() {
  Serial.begin(115200);
}

void loop() {

  Serial.println("Top of the loop");
  forward(200);
  delay(1000);

  leftTurn(200);
  delay(1000);
  //reverse(200);
  forward(200);
  delay(1000);
  
  leftTurn(200);
  delay(1000);
  forward(200);
  delay(1000);
  leftTurn(200);

  delay(1000);
  forward(200);
  delay(1000);
  leftTurn(200);
  delay(1000);
  
  //ProcessCommand();
  /*
  Motor1.SetSpeed(m1);   
  Motor2.SetSpeed(m2);
  Motor3.SetSpeed(m3);
  Motor4.SetSpeed(m4);
  */
}

void forward(int speed) {
  m1.SetSpeed(speed);
  m2.SetSpeed(speed);
  m3.SetSpeed(speed);
  m4.SetSpeed(speed);
}

void reverse(int speed) {
  speed = -speed;
  m1.SetSpeed(speed);
  m2.SetSpeed(speed);
  m3.SetSpeed(speed);
  m4.SetSpeed(speed);
}

void leftTurn(int speed) {
  m1.SetSpeed(speed);
  m4.SetSpeed(speed);
  
  m3.SetSpeed(50);
  m2.SetSpeed(50);
    
}

void ProcessCommand()
{
  static unsigned long lastCmdIn = 0;
  int c;
  if (Serial.available() > 0 )
  {
    c = Serial.read();
    lastCmdIn = millis();
    switch (c)
    {
      case '0':
        m1 = 0;
        m2 = 0;
        m3 = 0;
        m4 = 0;
        break;
        
      case '1':
        s1 += 50;
        if (s1 > 255) s1 = 0;
        break;
          
      case '2':
        s2 += 50;
        if (s2 > 255) s2 = 0;
        break;

      case '3':
        s3 += 50;
        if (s3 > 255) s3 = 0;
        break;
        
      case '4':
        s4 += 50;
        if (s4 > 255) s4 = 0;
        break;

      case '0':
        s1 = 0;
        s2 = 0;
        s3 = 0;
        s4 = 0;
   
      default:
        break;
    }
  } else if (millis() - lastCmdIn > 300) {

  }
}
