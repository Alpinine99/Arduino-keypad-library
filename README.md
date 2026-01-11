# Simple to use 4x4 keypad library

## How it works

A library that allows you to connect to your desired avr board and communicate with a 4x4 keypad module directly without any pull up or pull down resistors. Its easy to use, only provide the module initialization api and reading keys.

## Installation

1. [Download](https://github.com/Alpinine99/Arduino-keypad-library/archive/refs/heads/main.zip) zip from the main repo.

2. Navigate to arduino install from zip option and click your downloaded zip file.

3. Include in your project you are all set.

![Installation](/resources/install-zip-library.gif)

## How to use

- initialize your pins as connected to you module and setup the keys as you desire.

> Make sure you use an array for then pass it to the `Keypad` class as it takes a pointer as a default parameter.

```c
const int ROWS[4] = { 5, 4, 3, 2 }; // { R1, R2, R3, R4 }
const int COLUMNS[4] = { 6, 7, 8, 9 }; // { C1, C2, C3, C4 }
const char DIAL[4][4] = {{ '1', '2', '3', 'A' }, { '4', '5', '6', 'B' },
                        { '7', '8', '9', 'C' }, { '*', '0', '#', 'D' }};

KeypadLib Keypad(ROWS, COLUMNS, DIAL);
```

- Call the `Keypad.pinSetup()` api to setup the objects pins.

- On the loop call `char key = Keypad.readKey(KeypadLib::RELEASED)` which takes `KeypadLib::RELEASED` or `KeypadLib::PRESSED` to specify the mode, and returns a `char` of the key set on the initialization.

> Note: by default the returned character is `_` and you can catch that on your code.

### Hope you find it useful 😌
