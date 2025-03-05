#include <Arduino.h>

#define TINY_GSM_MODEM_SIM800

#include <LiquidCrystal_I2C.h>
#include <TinyGSM.h>
#include <SoftwareSerial.h>

#include <pins.h>
#include <setup.h>

SoftwareSerial gsmSerial{Pins::RX, Pins::TX}; // serial for GSM communication
LiquidCrystal_I2C lcd{0x27, 16, 2};           // set the LCD address to 0x27 for a 16 chars and 2 line display
TinyGsm modem{gsmSerial};                     // GSM module SIM800L

/**
 * Setup function.
 *
 * This function is called once when the program starts.
 * It is used to initialize the program.
 *
 * This function initializes the GSM module, the LCD display, the pins, and the serial communication.
 * It also tests its outputs one-by-one.
 */
void setup()
{
    setupPins();   // initialize the pins
    testOutputs(); // test the outputs

    gsmSerial.begin(9600); // initialize GSM serial communication
    lcd.init();            // initialize the LCD display
}

void loop()
{
}
