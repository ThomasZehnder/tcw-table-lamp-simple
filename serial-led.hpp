#ifndef serial_led_h
#define serial_led_h

extern char pinOutputs[4];


void ledInit(void);

void ledCommand(unsigned char ledNr, unsigned char intensity);

void ledPulse(unsigned char selectedPinOutput);

#endif //serial_led_h