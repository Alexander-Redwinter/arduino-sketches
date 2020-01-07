#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#include <Keypad.h>

#define C4 2
#define C3 3
#define C2 4
#define C1 5
#define R1 6
#define R2 7
#define R3 8
#define R4 9

#define RED      0xF800
#define PIN 10

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns

byte rowPins[ROWS] = {R1, R2, R3, R4}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {C1, C2, C3, C4}; //connect to the column pinouts of the keypad

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', '4'},
  {'5', '6', '7', '8'},
  {'9', 'A', 'B', 'C'},
  {'D', 'E', 'F', 'G'}
};

Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);


// MATRIX DECLARATION:
// Parameter 1 = width of NeoPixel matrix
// Parameter 2 = height of matrix
// Parameter 3 = pin number (most are valid)
// Parameter 4 = matrix layout flags, add together as needed:
//   NEO_MATRIX_TOP, NEO_MATRIX_BOTTOM, NEO_MATRIX_LEFT, NEO_MATRIX_RIGHT:
//     Position of the FIRST LED in the matrix; pick two, e.g.
//     NEO_MATRIX_TOP + NEO_MATRIX_LEFT for the top-left corner.
//   NEO_MATRIX_ROWS, NEO_MATRIX_COLUMNS: LEDs are arranged in horizontal
//     rows or in vertical columns, respectively; pick one or the other.
//   NEO_MATRIX_PROGRESSIVE, NEO_MATRIX_ZIGZAG: all rows/columns proceed
//     in the same order, or alternate lines reverse direction; pick one.
//   See example below for these values in action.
// Parameter 5 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_GRBW    Pixels are wired for GRBW bitstream (RGB+W NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)


// Example for NeoPixel Shield.  In this application we'd like to use it
// as a 5x8 tall matrix, with the USB port positioned at the top of the
// Arduino.  When held that way, the first pixel is at the top right, and
// lines are arranged in columns, progressive order.  The shield uses
// 800 KHz (v2) pixels that expect GRB color data.
Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(32, 8, PIN,
                            NEO_MATRIX_TOP     + NEO_MATRIX_LEFT +
                            NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,
                            NEO_GRB            + NEO_KHZ800);

const uint16_t colors[] = {
  matrix.Color(100, 0, 0), matrix.Color(0, 0, 0), matrix.Color(0, 0, 0)
};

void setup()
{
  matrix.begin();
  matrix.setTextWrap(false);
  matrix.setBrightness(1);
  matrix.setTextColor(RED);
  clear();

}

/*int x    = matrix.width();
  int pass = 0;*/

void loop()
{
  char customKey = customKeypad.getKey();
  if (customKey)
  {
    switch (customKey)
    {
      case '1':
        drawYes();
        break;
      case '2':
        drawUwu();
        break;
      case '3':
        drawNo();
        break;
              case '4':
        drawSleepy();
        break;
              case '5':
        drawSmileyFace();
        break;
      default:
        clear();
    }
  }


}

void drawYes()
{
  matrix.fillScreen(0);
  matrix.setCursor(10, 0);
  matrix.print("YES");
  matrix.show();
}

void drawUwu()
{
  matrix.fillScreen(0);
  matrix.setCursor(10, 0);
  matrix.print("UwU");
  matrix.show();
}

void drawNo()
{
  matrix.fillScreen(0);
  matrix.setCursor(10, 0);
  matrix.print("NO");
  matrix.show();
}

void drawSleepy()
{
  matrix.fillScreen(0);
  matrix.setCursor(0, 1);
  matrix.print("Zzz");
  matrix.show();
}

void drawSmileyFace()
{
  matrix.fillScreen(0);
  matrix.setCursor(0, 1);
  matrix.print(":D");
  matrix.show();
}

void clear()
{
  matrix.fillScreen(0);
  matrix.show();
}
//Scrolling text
/*if(--x < -36) {
  x = matrix.width();
  if(++pass >= 3) pass = 0;
  matrix.setTextColor(colors[pass]);
  }*/
