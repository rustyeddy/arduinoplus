#ifndef __OSEPP_MOTOR_H__
#define __OSEPP_MOTOR_H__

#include <Arduino.h>

class OseppTBMotor
{
  private:
    uint8_t _dir_pin, _pwm_pin;

  public:
    OseppTBMotor(uint8_t dir_pin, uint8_t pwm_pin);

    void forward(uint8_t speed);
    void reverse(uint8_t speed);
    void SetSpeed(int speed);
};

#endif // OseppTBMotor
