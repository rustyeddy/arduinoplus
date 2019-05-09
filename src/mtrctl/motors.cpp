#include "motors.h"
#include "tlvs.h"

int s1 = 500;
int s2 = 500;
int s3 = 500;
int s4 = 500;

OseppTBMotor m1(12, 11); // these are SPI chips
//OseppTBMotor m3(7, 6);

// only 2
OseppTBMotor m2(8, 3);
//OseppTBMotor m4(4, 5);

int debug_motors= 0;

// do_motors will handle the incoming motor command
void do_motors(TLVS *args) {
    float msg_num = args->get_arg(1).toInt();
    float lspeed = args->get_arg(2).toFloat();
    float rspeed = args->get_arg(3).toFloat();

    if (debug_motors) {
	Serial.print("motor command number: "); Serial.println(msg_num);
	Serial.print("\tL: "); Serial.println(lspeed);
	Serial.print("\tR: "); Serial.println(rspeed);
    }
    if (lspeed > 0) {
	m1.forward(lspeed);	
    } else {
	m1.reverse(lspeed);
    }

    if (rspeed > 0) {
	m2.forward(rspeed);	
    } else {
	m2.reverse(rspeed);
    }

}
