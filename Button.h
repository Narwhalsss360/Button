/*
	Button - a small library for Arduino to handle button debouncing
	
	MIT licensed.
*/

#ifndef Button_h
#define Button_h
#include "Arduino.h"

class Button
{
	public:
		Button(uint8_t pin, uint16_t debounce_ms = 100);
		void begin();
		void begin(void (*)(void));
		bool read();
		bool toggled();
		bool pressed();
		bool released();
		bool has_changed();
		
		const static bool PRESSED = LOW;
		const static bool RELEASED = HIGH;
	
	private:
		void (*_on_change_callback)(void);
		uint8_t  _pin;
		uint16_t _delay;
		bool     _state;
		uint32_t _ignore_until;
		bool     _has_changed;
};

#endif