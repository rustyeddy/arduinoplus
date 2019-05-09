#include <Arduino.h>
#include "tlvs.h"
#include "motors.h"

void do_hello(TLVS *tlv) {
    Serial.print(tlv->get_arg(1));
    Serial.println("version=1");
}

TLVS::TLVS(char *buf) {
    // Set the raw and parsed buffers as though they are private
    // variables.  That way, if this library needs to become re-entrant
    // we can properly sync the data buffers.
    _parsed_buf = buf;

    // Copy the original input buffer into a new making he
    // parsed_buffer immutable.
    strncpy(_parsed_buf, _parsed_buf, strlen(buf));

    // Set up our arg count and values
    _reset_args();

    // Gahead and parse the incoming data
    parse(buf);
}


String TLVS::get_arg(int num) {
    if (num > _argc) {
	Serial.print("Error argument number too big "); Serial.println(num);
	return String();
    }
    String str =  String(_args[num]);
    return str;
}

// mot:6:x=99:y=55:but=4
int TLVS::parse(char *rawbuf)
{
    _argc = 0;
    int len = strlen(rawbuf);
    int newword = 0;
    strncpy(_parsed_buf, rawbuf, len);
    _args[_argc] = _parsed_buf;
	
    // Serial.print("Walking new string "); Serial.println(strlen(_parsed_buf));
    // Serial.print("Argc "); Serial.println(_argc);

    int i = 0;
    for (; i < len; i++){
	if (newword) {
	    if (_debug) {
		Serial.print("neword saving argc ~ "); Serial.println(_argc); 
		Serial.print("\tsaved ... "); Serial.println(_args[_argc]);
	    }
	    _argc += 1;
	    _args[_argc] = &_parsed_buf[i]; // saving the next param
	    newword = 0;
	}

	if (_parsed_buf[i] == _delim) {
	    _parsed_buf[i] = '\0'; // terminate this argument
	    newword = 1;
	    // Serial.print("Saved arg "); Serial.print(_argc); Serial.print(": "); Serial.println(_args[_argc]);
	}
    }
    _argc += 1;
    // Serial.print("leaving parsed buf ~ argc = "); Serial.println(_argc);
    return _argc;
}

void TLVS::dump() {
    Serial.print("Command cnt "); Serial.println(_argc);
    for (int i = 0; i < _argc; i++) {
	Serial.print("\t"); Serial.print(i); Serial.print(" => "); Serial.println(_args[i]);
    }
}

void TLVS::do_command() {
    char *cmd = _args[0];
    if (!strncmp("mot", cmd, 3)) {
	do_motors(this);	
    } else if (!strncmp("helo", cmd, 4)) {
	do_hello(this);
    }
}

void clear_buffer(char *buf) {
    for (int i = 0; i < MAX_LINE; i++) {
	buf[i] = '\0';
    }
}
