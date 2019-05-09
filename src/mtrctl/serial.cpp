#include <Arduino.h>
#include "serial.h"

// TODO make a hex dump with char printing on the side, some day ..
void dump(char *buf, int size) {
    Serial.println("packet");
    
    for (int i = 0; i < size; i++) {
	char ch = buf[i];
	if ((i % 16) == 0) {
	    Serial.println();
	}

	if (isPrintable(ch)) {
	    Serial.print(ch);
	} else {
	    Serial.print(".");
	}
    }
    Serial.println();
}

// serial_newline() will read from the serial port a string upto a newline
// or line termination character.  If nothing is available at the prompt
// a null string will be returned.
int serial_newline(char *buffer, int maxline) {
    char *ptr = buffer;
    int dotcnt = 0;
    int count = 0;

    // gobble up what we can get, expect a nl or \0 to terminate
    while (Serial.available() > 0 && count < maxline) {

	// Get the next character waiting
	int ch = Serial.read();

	switch (ch) {

	case '\0':
	case '\n':
	case '\r':
	    *ptr = '\0';
	    break;

	case -1:
	    Serial.print("ERROR reading input: "); Serial.println(buffer);
	    break;

	default:
	    count++;
	    *ptr++ = ch;
	}
    }

    if (debug_serial) {
	if (dotcnt >= 69) {
	    Serial.println("<cr>");
	    dotcnt = 0;
	} else {
	    Serial.print(".");
	    dotcnt++;
	}
    }
    return count;
}
