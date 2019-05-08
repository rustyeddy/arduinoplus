#ifndef __MOTORS_H__
#define __MOTORS_H__

#include "tlvs.h"
#include "TBMotor.h"

// do_motors will handle the incoming motor command
static void do_motors(TLVS *args) {
    float msg_num = args->get_arg(1).toInt();
    float lspeed = args->get_arg(2).toFloat();
    float rspeed = args->get_arg(3).toFloat();

    Serial.print("motor command number: "); Serial.println(msg_num);
    Serial.print("\tL: "); Serial.println(lspeed);
    Serial.print("\tR: "); Serial.println(rspeed);
}

#endif // __MOTORS_H__
