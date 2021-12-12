#ifndef serial_display_h
#define serial_display_h

#include <Wire.h>
#include "SSD1306Ascii.h"
#include "SSD1306AsciiWire.h"

extern SSD1306AsciiWire display;

void displayInit(void);

void serialPlusOled(char *s);



#endif //serial_display_h
