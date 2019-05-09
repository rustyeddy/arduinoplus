
//include motor code
// #include "TBMotor.h"
#include "tlvs.h"
#include "motors.h"
#include "serial.h"

int dotcnt = 0;
int debug = 1;

void setup() {
    Serial.begin(115200);
}

// Create buffers for incoming serial command and the corresponding
// parsed buffer.  We are running in a tight loop with no interrupts
// hence it is ok to use a single buffer, we'll allocate all the mem
// we need at startup and reuse the same memory for ever.
//
// The incoming raw data (line of input) will be coped to another buffer
// making it *immutable*, to be parsed into an array of strings (or a
// map of strings indexed by strings)...
static int dodelay = 1;

int delay_millis = 500;

// Round and Round we go ...
void loop() {
    TLVS *msg = NULL;
    char *cmd = NULL;

    // The following function will not block, null will be returned

    int count = serial_newline(_incoming_buffer, MAX_LINE_SIZE);
    if (count <= 0) {
	dodelay = 1; // go ahead sure we delay next round
	goto next;
    }

    Serial.println(""); Serial.print("We gots us a new command: ");
    Serial.println(_incoming_buffer);

    // TLVs will parse the incoming newline into a argument array
    msg = new TLVS(_incoming_buffer);
    if (msg == NULL) {
	Serial.println("Error reading next message");
	goto next;
    }

    if (debug) {
	Serial.println("Successfully Read Message");	
    }
    cmd  = msg->get_cmd();
    if (strcmp(cmd, "mot")) {
	// we will expect L & R speeds
	do_motors(msg);
    }
    msg->dump();

 next:
    // re-initialize the entire buffer for the next incoming!
    if (_incoming_buffer[0] != '\0') {
	int slen = strlen(_incoming_buffer);
	if (slen > 0) {
	    for (unsigned int i = 0; i < strlen(_incoming_buffer); i++) {
		_incoming_buffer[i] = '\0';
	    }
	}
    }

    if (dodelay) {
	delay(delay_millis);
    }
}

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
