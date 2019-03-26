#include <Arduino.h>
#include <Wire.h>
#include "i2c.h"
#include "cmd.h"

char i2c_buffer[32];
byte i2c_ouraddr = 0x11;

void i2c_setup() {
  // Become a slave on the i2c bus
  Wire.begin(i2c_ouraddr);
  Wire.onReceive(i2c_incoming);
}

void
i2c_incoming(int avail) {
  char *cmds[10];
  int cmd = 1;

  cmds[0] = i2c_buffer;
  char *ptr = i2c_buffer;
  for (int i = 0; i < 32 && Wire.available(); ptr++, i++) {
    *ptr = Wire.read();
    if (*ptr == ':') {
      *ptr = '\0';
      if (cmds[cmd] == 0) {
	cmds[cmd++] = ptr;
      }
    }
  }
  do_command(cmds, cmd);
}

