#include <SPI.h>
#include "RF24.h"

#include "tmp32.h"

#define TEMP32_PIN	A0

// RF24 Pins 
#define RADIO_P1	7
#define RADIO_P2	8

Temp32 *temp = NULL;
RF24 radio( RADIO_P1, RADIO_P2 );

void setup() {
    Serial.begin(115200);

    temp = new Temp32(TEMP32_PIN);
    assert(temp);

    // Set the PA Level low to prevent power supply related issues since this is a
    // getting_started sketch, and the likelihood of close proximity of the devices. RF24_PA_MAX is default.
    //radio.setPALevel(RF24_PA_MAX);
    Serial.println("Radio");
    radio.setRetries(15, 15);
    radio.setPALevel(RF24_PA_LOW);
    byte *ouraddr = (byte *)"nan01";
    radio.openWritingPipe(ouraddr);
    Serial.println("Goodbye");
}

void loop() {
    Serial.print("Here we go again, ");

    // Report the temprature
    char *str = temp->Report();
    Serial.println(str);

    /*
    if (!radio.write(str, strlen(str))) {
	Serial.println("Error writing ");
    } 
    */
    delay(2000);
}
