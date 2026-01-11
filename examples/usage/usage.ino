#include "KeypadLib.h"

const int ROWS[4] = { 5, 4, 3, 2 }; // { R1, R2, R3, R4 }
const int COLUMNS[4] = { 6, 7, 8, 9 }; // { C1, C2, C3, C4 }
const char DIAL[4][4] = {{ '1', '2', '3', 'A' }, { '4', '5', '6', 'B' },
                        { '7', '8', '9', 'C' }, { '*', '0', '#', 'D' }};

KeypadLib Keypad(ROWS, COLUMNS, DIAL);

void setup() {
  Serial.begin(115200);
  Keypad.pinSetup();
}

void loop() {
  char key = Keypad.readKey(KeypadLib::RELEASED);
  if (key != '_')
    Serial.println(key);
}