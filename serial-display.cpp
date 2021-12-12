#include "Arduino.h"
#include "tcw-table-lamp-simple-defines.hpp"
#include "serial-display.hpp"


SSD1306AsciiWire display;

// SCL to arduino pin A5
// SDA to arduino pin A4

// 0X3C+SA0 - 0x3C or 0x3D
#define I2C_ADDRESS 0x3C

void displayInit(void)
{
  Wire.begin();
  Wire.setClock(400000L);
  display.begin(&Adafruit128x64, I2C_ADDRESS);
  display.setScrollMode(SCROLL_MODE_AUTO);

  display.setFont(fixed_bold10x15);
  display.clear();
  display.println("TCW LAMP SIMPLE");

  //display.setFont(lcd5x7);
  display.println(String("V") + VERSION);
  display.println(MY_BOARD_TYPE);

  display.print("Build: ");
  display.println(BUILD_DATE);
  display.println(BUILD_TIME);

}


void serialPlusOled(char *s)
{
  Serial.println(s);
  display.println("");
  display.print(s);
}

void serialPlusOledDelayed(char *s)
{
  serialPlusOled(s);
  delay(50);
}





