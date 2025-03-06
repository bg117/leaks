#include <Arduino.h>

#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>

#include <pins.h>
#include <setup.h>

SoftwareSerial gsmSerial{Pins::TX, Pins::RX}; // serial for GSM communication
LiquidCrystal_I2C lcd{0x27, 16, 2};           // set the LCD address to 0x27 for a 16 chars and 2 line display

void lcd_clearAndPrint(const char *message)
{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(message);
}

void updateSerial()
{
    delay(500);
    while (Serial.available())
        gsmSerial.write(Serial.read()); // Forward what Serial received to Software Serial Port
    while (gsmSerial.available())
        Serial.write(gsmSerial.read()); // Forward what Software Serial received to Serial Port
}

void sendATCommand(const char *command)
{
    gsmSerial.println(command);
    delay(500);
    while (gsmSerial.available())
        Serial.write(gsmSerial.read());
    Serial.println();
}

void gsmSetup()
{
    sendATCommand("AT");        // check if the GSM module is working
    sendATCommand("AT+CMEE=2"); // set extended error reporting
    sendATCommand("AT+CSQ");
    sendATCommand("AT+CCID");
    sendATCommand("AT+CREG?");
    sendATCommand("AT+CMGF=1");                 // set the GSM module to text mode
    sendATCommand("AT+CMGS=\"+639296646300\""); // set number
}

void sendSMS(const char *message)
{
    sendATCommand(message);
    gsmSerial.write((char)26); // send the ASCII code of CTRL+Z
}

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
    Serial.begin(9600);    // initialize serial communication
    gsmSerial.begin(9600); // initialize GSM serial communication

    while (!Serial || !gsmSerial)
        ; // wait for the serial port to open

    delay(7000); // wait for 10 seconds to ensure the GSM module is ready
    gsmSetup();  // initialize the GSM module

    lcd.init();      // initialize the LCD display
    lcd.backlight(); // turn on the backlight
    lcd_clearAndPrint("Initializing pins");

    setupPins(); // initialize the pins

    lcd_clearAndPrint("We are LIVE"); // start the message
}

void loop()
{
    updateSerial(); // update the serial communication

    bool front = !isActive(Pins::FRONT_MQ),
         left = !isActive(Pins::LEFT_MQ),
         back = !isActive(Pins::BACK_MQ),
         right = !isActive(Pins::RIGHT_MQ);

    // if none of the sensors are active
    if (front + left + back + right == 0)
    {
        // turn off motors
        digitalWrite(Pins::LEFT_MOTOR, LOW);
        digitalWrite(Pins::RIGHT_MOTOR, LOW);

        // turn off vacuum
        digitalWrite(Pins::VACUUM, HIGH);
        return;
    }

    // turn on vacuum
    digitalWrite(Pins::VACUUM, LOW);

    // if front sensor is not active, turn left until it is
    // unless the right sensor is active, in which case turn right
    if (isActive(Pins::FRONT_MQ))
    {
        if (right)
        {
            // turn right
            digitalWrite(Pins::LEFT_MOTOR, HIGH);
            digitalWrite(Pins::RIGHT_MOTOR, LOW);
        }
        else
        {
            // turn left
            digitalWrite(Pins::LEFT_MOTOR, LOW);
            digitalWrite(Pins::RIGHT_MOTOR, HIGH);
        }
    }
    else
    {
        // move forward
        digitalWrite(Pins::LEFT_MOTOR, HIGH);
        digitalWrite(Pins::RIGHT_MOTOR, HIGH);
    }
}
