#include <Arduino.h>
#include "joystick.h"

Joystick::Joystick() {
    Setup(0, 0, 0);
};

Joystick::Joystick(int x, int y, int b) {
    Setup(x, y, b);
};

void Joystick::Setup(int x, int y, int sw) {
    _pinX = x;
    _pinY = y;
    _pinSW = sw;

    // The last numbers
    _lastX = lastY = 0;
    _lastSW = 77; // a nonsense number forcing it to be reset
    pinMode(pinSW, INPUT);
    digitalWrite(pinSW, HIGH);

    // Turn off report changes by default
    ReportChanges = 0;
};

/*
 * Joystick report will send a packet either everytime it is asked,
 * or it will only send a packet when something has changed, depending
 * on the report_changes flag.
 */
tlv Joystick::Report() {
    tlv char[6];
    tlv[0] = 0x02;
    tlv[1] = 0x03;

    int sw = digitalRead(_pinSW);
    int x = analogRead(_pinX);
    int y = analogRead(_pinY);

    // Report changes is broken!
    if (report_changes == 1) {
	if (_lastSW == sw && _lastX == x && _lastY == y) {
	    goto finished;
	}
	
	int dx = x - _lastX;
	int dy = y - _lastY;
	int dsw = _lastSW - sw;
	tlv[2] = dx;
	tlv[3] = dy;
	tlv[4] = dsw;
	tlv[5] = '\n';
    } else {
	tlv[2] = sw;
	tlv[3] = x;
	tlv[4] = y;
	tlv[5] = '\n';
    }
    Serial.print("jd:"); Serial.print(dsw);
    Serial.print(":"); Serial.print(dx);
    Serial.print(":"); Serial.println(dy);
} else {
    Serial.print("jc:"); Serial.print(sw);
    Serial.print(":"); Serial.print(x);
    Serial.print(":"); Serial.println(y);
 }

  // Alternative
  // msg[0] = 'j'; msg[1] = 6; msg[2:3] = x; y = msg[4:5]; sw = msg[6];
  // TLV above

 finished:
  _lastX = x;
  _lastY = y;
  _lastSW = sw;
}
