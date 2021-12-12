
//   tcw table lamp simple
//  V1.00

#include "arduino-bord-check.hpp"

#include "tcw-table-lamp-simple-defines.hpp"

#include "serial-display.hpp"
#include "serial-key.hpp"
#include "serial-led.hpp"

unsigned char intensity=0;

void setup()
{
    // initialize serial: baud rate fix to 115200
    Serial.begin(115200);

    // setup OLED display
    // SCL to arduino pin A5
    // SDA to arduino pin A4
    displayInit();

    // initialize keys
    keyInit();

    // initialize led's
    ledInit();

    pinMode(PIN_OUTPUT_0, OUTPUT);

    Serial.println("################################################################");
    Serial.println(" tcw-table-lamp-simple");
    Serial.println("################################################################");
    Serial.println(BUILD_DATE_TIME);
    Serial.println(MY_BOARD_TYPE);
}

void loop()
{
    ledCommand(0, 255);

    delay(100);
    display.print('*');

    ledCommand(0, 0);

    delay(400);
    serialPlusOled("BLINK");
    if (keyPressed(0))
    {
        //serialPlusOled("closed");
        ledCommand(1, 255);
        intensity += 16;
        ledCommand(2, intensity);
    }
    else
    {
        //serialPlusOled("open");
        ledCommand(1, 0);
    }
}