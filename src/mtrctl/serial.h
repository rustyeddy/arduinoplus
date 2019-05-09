#ifndef __SERIAL_H__
#define __SERIAL_H__

// Just for the serial 
static char _incoming_buffer[MAX_LINE_SIZE];
static int _debug = 0;

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

    if (_debug) {
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

#endif // SERIAL_H_
