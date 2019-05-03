// Mobile Robot I/O 2019-03-04

#include <Wire.h>

#include "i2c.h"
#include "joystick.h"
#include "distance.h"
#include "RF24.h"
#include "rf24l01.h"

// Joystick pins, analog X and Y
#define JOYSTICK_PX	A0
#define JOYSTICK_PY	A1
#define JOYSTICK_PSW	D2

#define RADIO_P1	A7
#define RADIO_P2	A8

RF24 *rf = NULL;
Joystick *joy = NULL;
Distance *dist = NULL;

#define TLV_BUFSIZ 0xff

// We only need a single buffer since we are not going to do any
// concurrency, strickly a tight non-blocking loop.
char tlvbuf[BUFSIZ];

const byte data_pipe[6] = "00001";
int delay_time = 100;

void setup() {

    // Get the serial port going
    Serial.begin(115200);

    // Comment out if RF is not to be run
    rf = new RF24(RADIO_P1, RADIO_P2);
    if (rf != NULL) {
	
    }
    // Comment out Joystick if not using
    joy = new Joystick(JOYSTICK_PX, JOYSTICK_PY, JOYSTICK_PSW);

    i2c_setup();
}

void rf24_setup() {
  radio.begin();
  radio.setRetries(15, 15);
  radio.setPALevel(RF24_PA_LOW);
  radio.openWritingPipe(data_pipe);
}


void loop() {
    if (dist == NULL && joy == NULL) {
	Serial.println("nothing to do, wait for a config change");
    }
    if (dist != NULL) {
	data = dist->Report();
	radio.write(data, strlen(data));
    }
    if (joy != NULL) {
	data = joy->Report();
	radio.write(data, strlen(data));
    }
    delay(delay_time);
}

