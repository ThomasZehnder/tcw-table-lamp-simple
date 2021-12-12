#include "Arduino.h"
#include "tcw-table-lamp-simple-defines.hpp"
#include "serial-led.hpp"
#include "serial-display.hpp"

char pinOutputs[4];

void ledInit(void)
{
  pinOutputs[0] = PIN_OUTPUT_0;
  pinOutputs[1] = PIN_OUTPUT_1;
  pinOutputs[2] = PIN_OUTPUT_2;
  pinOutputs[3] = PIN_OUTPUT_3;

  unsigned char i;
  // initialize digital pin LED_BUILTIN as an output.
  for (i = 0; i < 4; i++)
  {
    pinMode(pinOutputs[i], OUTPUT);
    digitalWrite(pinOutputs[i], LOW); // turn the LED off by making the voltage LOW

    // initial demo flashing
    ledPulse(i);
  }
}

void ledPulse(unsigned char selectedPinOutput)
{
  ledCommand(selectedPinOutput, 255);
  delay(100);
  ledCommand(selectedPinOutput, 0);
  delay(100);
}

void ledCommand(unsigned char selectedPinOutput, unsigned char intensity)
{
  char line[30];

  if (intensity == 255)
  {
    digitalWrite(pinOutputs[selectedPinOutput], HIGH); // turn the LED on (HIGH is the voltage level)
  }
  else if (intensity == 0)
  {
    digitalWrite(pinOutputs[selectedPinOutput], LOW); // turn the LED on (HIGH is the voltage level)
  }
  else
  {
    analogWrite(pinOutputs[selectedPinOutput], intensity); // %
  }

  sprintf(line, "o[%i]=%i", selectedPinOutput, intensity);
  serialPlusOled(line);
}
