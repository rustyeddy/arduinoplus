#include <string.h>
#include "cmd.h"

int cmd_errors = 0;

void do_command(char *cmds[], int cnt) {
  char *cmd = cmds[0];

  // m == motor speed + 
  if (!strcmp(cmd, "ms")) {
    // do something
    
  } else if (!strcmp(cmd, "rst")) {
    if (cnt != 0) {
      cmd_errors = 0;
    }
  } else if (!strcmp(cmd, "stp")) {
    
  } else {
    // Unknown command?
  }
  
}
