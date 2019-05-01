#ifndef __LED_H__
#define __LED_H__

#ifdef esp8266
#define ON	LOW
#define OFF	HIGH
#else
#define ON	HIGH
#define OFF	LOW
#endif


// LED creates an LED class that will control a single LED at
// the specified PIN
class LED {
private:
    int _pin;
    int _state;

public:
    LED() {}
    LED(int p, int s) {
	Init(p, s);
    }

    void Init(int p, int s) {
	_pin = p;
	_state = s;
	pinMode(_pin, OUTPUT);
    }

    // On turns the LED on, that's right the 8266 turns voltage HIGH
    // when the PIN is LOW or OFF.  
    void On() {
	digitalWrite(_pin, ON); //
	_state = ON;
    }
    void Off() {
	digitalWrite(_pin, OFF);
	_state = OFF;
    }

    int Toggle() {
	if (_state == OFF) {
	    _state = ON;
	} else {
	    _state = OFF;
	}
	digitalWrite(_pin, _state);
	return _state;
    }
};

#endif /* __LED_H__ */
