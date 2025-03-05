#include <setup.h>
#include <pins.h>

#include <Arduino.h>

void setupPins()
{
    pinMode(Pins::GREEN_LED, OUTPUT);
    pinMode(Pins::RED_LED, OUTPUT);

    pinMode(Pins::FRONT_MQ, INPUT);
    pinMode(Pins::LEFT_MQ, INPUT);
    pinMode(Pins::BACK_MQ, INPUT);

    pinMode(Pins::RIGHT_US_TRIG, OUTPUT);
    pinMode(Pins::CENTER_US_TRIG, OUTPUT);
    pinMode(Pins::LEFT_US_TRIG, OUTPUT);

    pinMode(Pins::RIGHT_US_ECHO, INPUT);
    pinMode(Pins::CENTER_US_ECHO, INPUT);
    pinMode(Pins::LEFT_US_ECHO, INPUT);

    pinMode(Pins::LEFT_MOTOR, OUTPUT);
    pinMode(Pins::RIGHT_MOTOR, OUTPUT);

    // turn OFF vacuum (active low relay)
    digitalWrite(Pins::VACUUM, HIGH);
    pinMode(Pins::VACUUM, OUTPUT);
}

void testOutputs()
{
    digitalWrite(Pins::GREEN_LED, HIGH);
    delay(1000);
    digitalWrite(Pins::GREEN_LED, LOW);

    digitalWrite(Pins::RED_LED, HIGH);
    delay(1000);
    digitalWrite(Pins::RED_LED, LOW);

    digitalWrite(Pins::LEFT_MOTOR, HIGH);
    delay(1000);
    digitalWrite(Pins::LEFT_MOTOR, LOW);

    digitalWrite(Pins::RIGHT_MOTOR, HIGH);
    delay(1000);
    digitalWrite(Pins::RIGHT_MOTOR, LOW);

    digitalWrite(Pins::VACUUM, LOW);
    delay(1000);
    digitalWrite(Pins::VACUUM, HIGH);
}