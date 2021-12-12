#ifndef tcw_table_simple_defines_h
#define tcw_table_simple_defines_h

#define VERSION "1.00ALFA"

//Operation Mode, switch with serial in @ and A, B, C, ...
#define OM_IOTEST 'A'
#define OM_TEMPMESSUREMENT 'B'

#if defined(ARDUINO_AVR_PRO)
// ARDUINO_PRO MINI
#define PIN_OUTPUT_0 LED_BUILTIN
#define PIN_OUTPUT_1 10
#define PIN_OUTPUT_2 11
#define PIN_OUTPUT_3 12

#define PIN_KEY_0 8
#define PIN_KEY_1 9

//Board Type, only support Arduino Pro Mini
#define MY_BOARD_TYPE "ARDUINO_AVR_PRO"


#else
#error Unsupported board selected. Stop compilation.
#endif

//BUILD DATE
#define BUILD_DATE_TIME __DATE__ "/" __TIME__
#define BUILD_TIME __TIME__
#define BUILD_DATE __DATE__

#endif //tcw_table_simple_defines_h