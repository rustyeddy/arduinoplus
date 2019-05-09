#ifndef __SERIAL_H__
#define __SERIAL_H__

#include "tlvs.h"

static int debug_serial = 0;

void dump(char *buf, int size);
int serial_newline(char *buffer, int maxline);


#endif // SERIAL_H_
