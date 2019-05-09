#ifndef __TLVS_H__
#define __TLVS_H__

#include <Arduino.h>

#define MAX_LINE_SIZE	256
#define MAX_ARGS	10

static char __parsed_buffer[MAX_LINE_SIZE];

// Running in a tight loop, only one set of incoming data possible.
// TLV String class 
class TLVS {
 protected:
    int _argc = 0;
    int _err = 0;      // no error yet
    int _msg_num = 0;
    char _delim = ':'; // configurable delimiter
    int _debug = 0;

    char *_parsed_buf;
    char *_raw_buf;
    char *_args[MAX_ARGS];

    void _reset_args() {
	_argc = 0;
	for (int i = 0; i < MAX_ARGS; i++) {
	    _args[i] = (char *) NULL;
	}
    }

 public:

    // TLVS will be created from a string.
    TLVS(char *buf) {

	// Set the raw and parsed buffers as though they are private
	// variables.  That way, if this library needs to become re-entrant
	// we can properly sync the data buffers.
	_raw_buf = buf;
	_parsed_buf = __parsed_buffer;

	// Copy the original input buffer into a new making he
	// parsed_buffer immutable.
	strncpy(_parsed_buf, buf, strlen(buf));

	// Set up our arg count and values
	_reset_args();

	// Gahead and parse the incoming data
	parse(buf);
    }

    String get_arg(int num) {
	if (num > _argc) {
	    Serial.print("Error argument number too big "); Serial.println(num);
	    return String();
	}
	String str =  String(_args[num]);
	return str;
    }

    // mot:6:x=99:y=55:but=4
    // Parse the _raw_buffer and turn into an argument array
    int parse(char *rawbuf) {

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

    void dump() {
	Serial.print("Command cnt "); Serial.println(_argc);
	for (int i = 0; i < _argc; i++) {
	    Serial.print("\t"); Serial.print(i); Serial.print(" => "); Serial.println(_args[i]);
	}
    }

    // Return the very first of the arguments and call it the command
    char *get_cmd() {
	return _args[0];
    }
};


#endif //__TLVS_H__
