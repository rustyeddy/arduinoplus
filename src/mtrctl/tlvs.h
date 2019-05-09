#ifndef __TLVS_H__
#define __TLVS_H__

#include <Arduino.h>

#define MAX_LINE 256
#define MAX_ARGS 10

void clear_buffer(char *buf);

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
    char *_args[MAX_ARGS];

    void _reset_args() {
	_argc = 0;
	for (int i = 0; i < MAX_ARGS; i++) {
	    _args[i] = (char *) NULL;
	}
    }

 public:

    // TLVS will be created from a string.
    TLVS(char *buf);

    String get_arg(int num);
    int parse(char *rawbuf);
    void dump();

    void do_command();
};


#endif //__TLVS_H__
