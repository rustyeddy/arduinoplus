#ifndef __TMP32_H__
#define __TMP32_H__

#include <assert.h>

// Temp32 is a temprature sensor
class Temp32 {
    int _pin;
    int _val;
    unsigned long _last_report;
    float _degrees;

 public:
    Temp32(int p) {
	_pin = p;
    }

    int Update() {
	_val = analogRead(_pin);
	return _val;
    }

    char* Report() {
	static char buf[80];

	int t = Update();
	
	double volts = t * 5.0;
	volts /= 1024.0;

	double tempC = (volts - 0.5) * 100;
	double tempF = (tempC * 9.0 / 5.0) + 32.0;
	sprintf(buf, "temp:raw=%d:c=%f:f=%f", t, tempC, tempF);
	_last_report = millis();
	return buf;
    }
};

#endif // __TMP32_H__
