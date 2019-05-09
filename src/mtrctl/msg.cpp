#include <Arduino.h>
#include "global.h"
#include "msg.h"

/*
int Message::ProcessIncoming(char *line, int max)
{
    int portid = -1; // not set
    char buffer[MAX_LINE];
    strcpy(buffer, line, strlen(line));

    char *ptr = buffer;
    char *proto = ptr;
    *(strchr(ptr, ':')) = 0; // pretty cool huh? :)
    
    assert((ptr - buffer) < max);
    char *topic = *(++ptr);
    if (ptr = strchr(topic, ':') || ptr = strchr(topic, '/')) {

	char str[] = "msg://joy:1/x=100,y=200,b=0";

	// We hit either a colon and we expect an integer to follow representing
	// the port, or in our case, an optional identifier.
	if (*ptr == ':') {
	    char *portptr = ++ptr;
	    ptr = strchr(portptr);
	}

	// look for the '/' or end it
	if ((*ptr == '/') || (*ptr == 0))  {
	    
	}
       
	
    } else {
	// Ptr is null, we will just assume the message is complete
	// and move along.
	
    }



    return 0; // Success
}

char *Message::BildOutgoing()
{
    
}
*/
