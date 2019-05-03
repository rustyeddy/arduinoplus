#ifndef __RF24_H__
#define __RF24_H__

static char tlvbuf[0xff];

static int rf24_tlv_get(char buf[], int max) {
    int len = 0;

 finished:
    return len;
}

// Write the given TLV to our RF24 radio
static int rf24_tlv_write(char buf[], int len) {
    
}

#endif  // __RF24_H__
