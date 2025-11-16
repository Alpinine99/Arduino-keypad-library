
#ifndef ARDUINO_KEYPADLIB_H
#define ARDUINO_KEYPADLIB_H
#include <Arduino.h>

class KeypadLib
{
private:
	int ROWS[4];
	int COLUMNS[4];
	int oldStates[4][4] = {{1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}};
	int readState[4][4];
	char KEYS[4][4];

public:
	KeypadLib(int *, int *, char[4][4]);
	typedef enum
	{
		PRESSED = 1,
		RELEASED = 0
	} State;
	void pinSetup();
	char readKey(State);
	~KeypadLib();
};
#endif
