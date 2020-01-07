#include <Keypad.h>

#define C4 2
#define C3 3
#define C2 4
#define C1 5
#define R1 6
#define R2 7
#define R3 8
#define R4 9

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns

byte rowPins[ROWS] = {R1, R2, R3, R4}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {C1, C2, C3, C4}; //connect to the column pinouts of the keypad

char hexaKeys[ROWS][COLS] = {
  {'1','2','3','4'},
  {'5','6','7','8'},
  {'9','A','B','C'},
  {'D','E','F','G'}
};

Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  char customKey = customKeypad.getKey();
  if (customKey){
        Serial.println(customKey);
  }
}
