//include motor code
// #include "TBMotor.h"
#include "global.h"
#include "tlvs.h"
#include "motors.h"
#include "serial.h"

int dotcnt = 0;
char incoming_buffer[MAX_LINE];
unsigned long last_time = 0;

void setup() {
    Serial.begin(115200);
    clear_buffer(incoming_buffer);
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
    unsigned long now = 0;
    // The following function will not block, null will be returned

    int count = serial_newline(incoming_buffer, MAX_LINE);
    if (count <= 0) {
	dodelay = 1; // go ahead sure we delay next round
	goto next;
    }

    if (debug_serial) {
	Serial.println(""); Serial.print("We gots us a new command: ");
	Serial.println(incoming_buffer);
    }

    // TLVs will parse the incoming newline into a argument array
    msg = new TLVS(incoming_buffer);
    if (msg == NULL) {
	Serial.println("err:0:Error reading next message");
	goto next;
    }

    if (debug_serial) {
	Serial.println("Successfully Parsed Message");	
    }

    msg->do_command();
    if (debug_serial) {
	msg->dump();	
    }

    now = millis();
    if (now - last_time > 5000)  {
	Serial.println("msg://helo/version=1");
	last_time = now;
    }

 next:
    // re-initialize the entire buffer for the next incoming!
    clear_buffer(incoming_buffer);
    if (dodelay) {
	delay(delay_millis);
    }
}
