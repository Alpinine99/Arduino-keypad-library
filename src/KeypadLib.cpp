#include "Arduino.h"
#include "KeypadLib.h"

KeypadLib::KeypadLib(int *rows, int *columns, char keys[4][4])
{
    for (int i = 0; i < 4; i++)
    {
        ROWS[i] = *(rows + i);
        COLUMNS[i] = *(columns + i);
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            KEYS[i][j] = keys[i][j];
    }
}

void KeypadLib::pinSetup()
{
    for (int i = 0; i < 4; i++)
    {
        pinMode(ROWS[i], OUTPUT);
        digitalWrite(ROWS[i], HIGH);
        pinMode(COLUMNS[i], INPUT_PULLUP);
    }
}

char KeypadLib::readKey(State s)
{
    char k = '_';
    for (int row = 0; row < 4; row++)
    {
        digitalWrite(ROWS[row], LOW);
        for (int column = 0; column < 4; column++)
        {
            delay(10);
            readState[row][column] = digitalRead(COLUMNS[column]);
            if (oldStates[row][column] == 1 && readState[row][column] == 0 && s == PRESSED)
                k = KEYS[row][column];

            else if (oldStates[row][column] == 0 && readState[row][column] == 1 && s == RELEASED)
                k = KEYS[row][column];

            oldStates[row][column] = readState[row][column];

            if (k != '_')
                break;
        }
        digitalWrite(ROWS[row], HIGH);
        if (k != '_')
            break;
    }
    return k;
}

KeypadLib::~KeypadLib()
{
}