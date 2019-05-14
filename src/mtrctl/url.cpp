#include <Arduino.h>
#include "url.h"

// URL should look like: msg://hostname.ocm:8080/path/to/endpoint/?a1=v1&a2=v2
int MSGURL::parse(const char *in) {

    char proto[5];
    char hostport[MAX_LINE];
    char path[MAX_LINE];
    int port;
    int rc = sscanf(s, "%s://%s:%d/%s", &proto, &host, &port, &path);
    if (rc < 0) {
	return -1;
    }


}
