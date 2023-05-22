#include "LedControl.h"

LedControl lc = LedControl(12, 11, 10, 1);

byte heart[] =
{
  B01100110,
  B11111111,
  B11111111,
  B11111111,
  B01111110,
  B00111100,
  B00011000,
  B00000000
};

void setup() {
  lc.shutdown(0, false);
  lc.setIntensity(0, 5);
  lc.clearDisplay(0);
}

void loop() {
  display_heart(1);
  delay(500);
  display_heart(0);
  delay(500);
}

void display_heart(int a)
{
  if (a == 0) {
    for (int i = 0; i < 8; i++)
    {
      lc.setRow(0, i, heart[i]);
    }
  } else {
    for (int i = 0; i < 8; i++)
    {
      lc.setRow(0, i, B00000000);
    }
  }
}