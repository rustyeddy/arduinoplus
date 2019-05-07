
/*
 * A pretty basic sketch to have sensor readings (i.e. joystick)
 * transmitted over RF then passed to and MQTT message bus.
 */

#include <SPI.h>
#include "RF24.h"

// RF24 Pins 
#define RADIO_P1 7
#define RADIO_P2 8

// Joystick PINs
#define JOY_PX	A0
#define JOY_PY	A1
#define JOY_PSW	2

/****************** User Config ***************************/
/***      Set this radio as radio number 0 or 1         ***/
bool radioNumber = 0;

/* Hardware configuration: Set up nRF24L01 radio on SPI bus plus pins 7 & 8 */
RF24 radio( RADIO_P1, RADIO_P2 );
/**********************************************************/

/** Create the Joystick **/
// joy = new Joystick(JOYSTICK_PX, JOYSTICK_PY, JOYSTICK_PSW);

byte *ouraddr = (byte *)"nan01";
byte *dstaddr = (byte *)"rpi04";
// byte addresses[][6] = {"nan01","rpi03"};

// Used to control whether this node is sending or receiving
bool role = 0;

#define BUFMAX 0xff
byte buffer[BUFMAX];
int buflen = 0;

void setup() {
    Serial.begin(115200);
    Serial.println(F("RF24/examples/GettingStarted"));
  
    radio.begin();
    radio.setRetries(15, 15);

    // Set the PA Level low to prevent power supply related issues since this is a
    // getting_started sketch, and the likelihood of close proximity of the devices. RF24_PA_MAX is default.
    //radio.setPALevel(RF24_PA_MAX);
    radio.setPALevel(RF24_PA_LOW);
    radio.openWritingPipe(ouraddr);
}

byte count = 0;
void loop() {
    report_joystick();
    delay(200);
}

// needcr toggles writting a carriage return below
static bool needcr = false;

void report_joystick() {
    int sw = digitalRead(JOY_PSW);
    int x = analogRead(JOY_PX);
    int y = analogRead(JOY_PY);

    char joystr[80];
    sprintf(joystr, "joy:msg=%02d:x=%d:y=%d:sw=%d", count++, x, y, sw);
    if (!radio.write(joystr, sizeof(joystr))) {
	Serial.print("e ");
	needcr = true;
    } else {
	if (needcr == true) {
	    Serial.println("");
	    needcr = false;
	}
	Serial.println(joystr);
    }
}
