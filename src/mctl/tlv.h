#ifndef __TLV_H__
#define __TLV_H__

// int get_tlv(char *buf)
int get_tlv(char *buf, int size) {
    int len = -1; // -1 means not set

    if (size == 0) goto finished;

    // read the first byte, which will be the type, that will
    // determine how much more to read
    if (! Wire.available()) {
	// add stats here?
	goto finished;
    }

    // read the type!
    buf[0] = Wire.read();

    // check if this is a compact message, set len to 1 and return
    if (buf[0] >= 0xC0) {
	len = 1;
	goto finished;
    }

    // Read the next value as the length, unless we have a short below
    if (! Wire.available()) {
	// Error if the next byte is not immediately ready.  XXX ~ this
	// is a real potential for returning before an expected next byte
	// is to arrive.  YHBW!
	goto finished;
    }
    buf[1] = Wire.read();

    // check for short message, if so: set len = 2; read next byte then return 
    if (buf[0] >= 0x80) {
	len = 2;
	return buf;
    } 
	
    // Now we have a regular tlv, we will need to read in the remaining
    len = buf[1]; // we will need this to read the remaining charactors

    // Now start the read loop according to the number of bytes we
    // have to be read.
    char *ptr = buf[2];
    for (int i = len - 2; i; i--) {
	buf[i] = Wire.read();
    }

 finished:
    return len;
}

// __TLV_H__
