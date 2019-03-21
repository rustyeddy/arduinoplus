#ifndef __TLV_H__
#define __TLV_H__

// -----------------------------------------
// TLV
// -----------------------------------------
#define MAX_DATA 16

class TLV
{
public:
    byte type;
    byte len;
    char buffer[MAX_DATA];

    TLV() {
        type = 0;
        len = 0;
    };

    TLV *Get();
    int Send(char *buf);
};

#endif /* __TLV_H__ */
