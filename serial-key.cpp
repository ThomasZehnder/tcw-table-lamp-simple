#include "Arduino.h"
#include "tcw-table-lamp-simple-defines.hpp"
#include "serial-key.hpp"
#include "serial-display.hpp"

bool valKey[2];
bool valKey_old[2];
int pinKey[2];

#define KEYTRUELEVEL false

void keyInit(void)
{
  pinKey[0] = PIN_KEY_0; 
  pinKey[1] = PIN_KEY_1; 

  int i;
  for (i = 0; i < 2; i++)
  {
    pinMode(pinKey[i], INPUT_PULLUP);
    valKey[i] = digitalRead(pinKey[i]);
    valKey_old[i] = valKey[i];
  }
}

bool keyPressed(int nr)
{
  return (digitalRead(pinKey[nr]) == KEYTRUELEVEL);
}

void sendJSON(int nr, char* value, bool serialToOledOn)
{
  char line[30];
  sprintf(line, "{\"key%i\":%s}", nr, value) ;
  if (serialToOledOn) 
  {
    //send only to serial out
    Serial.println(line);
  }
  else 
  {
    serialPlusOled(line);
  }
}

void keyEdgeDetect (bool serialToOledOn)
{
  int i;
  for (i = 0; i < 2; i++)
  {
    valKey[i] = digitalRead(pinKey[i]);
    if ((valKey[i] == KEYTRUELEVEL) && (valKey_old[i] == !KEYTRUELEVEL)) {
      sendJSON(i,"true", serialToOledOn);
    } else if ((valKey[i] == !KEYTRUELEVEL) && (valKey_old[i] == KEYTRUELEVEL)) {
      sendJSON(i,"false", serialToOledOn);
    }
    valKey_old[i] = valKey[i];
  }
}
