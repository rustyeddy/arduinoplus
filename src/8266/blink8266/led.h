#ifndef __LED_H__
#define __LED_H__

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
	digitalWrite(_pin, LOW); //
	_state = LOW;
    }
    void Off() {
	digitalWrite(_pin, HIGH);
	_state = HIGH;
    }

    int Toggle() {
	if (_state == HIGH) {
	    _state = LOW;
	} else {
	    _state = HIGH;
	}
	digitalWrite(_pin, _state);
	return _state;
    }
};

#endif /* __LED_H__ */
