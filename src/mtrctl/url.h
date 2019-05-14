#ifndef __URL_H__
#define __URL_H__

#define MAX_URL 256

class MSGURL {
 public:
    char string[MAX_URL];
    char parsed[MAX_URL];

    char *proto;
    char *host;
    char *port;
    char *path;
    char *args;

    MSGURL() {};
    char *parse(char *);
}

#endif  // __URL_H__
