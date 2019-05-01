
/*
 * TWO WHEELER BALANCING
 * 
 * Need to have "I2C dev" folder in Arduino libraries
 * Need to have "MPU6050" folder in Arduino libraries
 * Robot will try and balance itself using the MPU6050 sensor.
 *
 * Best used on OSEPP Mechanical Kits.
 * 2WBAL-01
 *
 * created 08 Nov 2016
 * by Sui Wei
 *
 */

//include motor code
#include "TBMotor.h"

int m1 = 0;
int m2 = 0;
int m3 = 0;
int m4 = 0;

OseppTBMotor Motor1(12, 11);
OseppTBMotor Motor2(8, 3);
OseppTBMotor Motor3(7, 6);
OseppTBMotor Motor4(4, 5);

void setup() {
  Serial.begin(115200);
  //updateIMU();
  //Change the timer frequency
  //To avoid the frequency of hearing.
  //TCCR2B &= ~7;
  //TCCR2B |= 1;
}

/*
const float offset_a = 2;

int leftSpeed;
int rightSpeed;
float ctrlTurn = 0;
float ctrlwalk = 0;

extern float angle;

float PID_Balance(float e, float kp, float ki, float kd)
{
  static float es = 0, sum = 0;
  float r;
  sum += e;
  if(sum>180)sum=180;else if(sum<-180)sum=-180;
  r = kp * e + ki * sum + kd * (e - es);
  es = e;
  return r;
}

void PIDSetSpeed()
{
  leftSpeed = rightSpeed = PID_Balance(angle+ctrlwalk, 20, 1, 60);
  leftSpeed+=ctrlTurn;
  rightSpeed-=ctrlTurn;

  ctrlTurn *= 0.95;
  ctrlwalk *= 0.9;

  if (leftSpeed > 255)leftSpeed = 255; else if (leftSpeed < -255)leftSpeed = -255;
  if (rightSpeed > 255)rightSpeed = 255; else if (rightSpeed < -255)rightSpeed = -255;
}
*/
void loop() {
  ProcessCommand();
  Motor1.SetSpeed(m1);   
  Motor2.SetSpeed(m2);
  Motor3.SetSpeed(m3);
  Motor4.SetSpeed(m4);
}

/*
void old_loop() {
  
  ProcessCommand();
  Motor1.SetSpeed(200);
  Motor2.SetSpeed(200);
  Motor3.SetSpeed(200);
  Motor4.SetSpeed(200);
  if(!updateIMU())return;
  
  PIDSetSpeed();

  if (abs(angle) < 45)
  {
    Motor1.SetSpeed(-leftSpeed);
    Motor2.SetSpeed(rightSpeed);
//    Serial.print(a);
//    Serial.print(",");
//    Serial.print(-leftSpeed);
//    Serial.print(",");
//    Serial.print(-rightSpeed);
//    Serial.println(",");
  } else {
    Motor1.SetSpeed(-0);
    Motor2.SetSpeed(-0);
  }
}
*/
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
         m1 += 50;
        if (m1 > 255) m1 = 0;
        break;
          
      case '2':
        m2 += 50;
        if (m2 > 255) m2 = 0;
        break;

      case '3':
        m3 += 50;
        if (m3 > 255) m3 = 0;
        break;
        
      case '4':
        m4 += 50;
        if (m4 > 255) m4 = 0;
        break;
        /*
      case 'U': case 'u':
        ctrlwalk = 2;
        break;
      case 'd':
        ctrlwalk = - 2;
        break;
      case 'L': case 'l':
        ctrlTurn = -45;
        break;
      case 'R': case 'r':
        ctrlTurn = 45;
        break;
      case 'A': case 'a':
        break;
      case 'C': case 'c':
        break;
      case 'B': case 'b':
        break;
      case 'D':
        break;
        */
      default:
        break;
    }
  } else if (millis() - lastCmdIn > 300) {

  }
}
