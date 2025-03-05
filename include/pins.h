#pragma once

#include <Arduino.h>

namespace Pins
{
    constexpr int RX = 11;
    constexpr int TX = 12;

    constexpr int GREEN_LED = 3;
    constexpr int RED_LED = 4;

    // MQ-9/6 pins (D0)
    constexpr int FRONT_MQ = A0;
    constexpr int LEFT_MQ = A1;
    constexpr int BACK_MQ = A2;
    constexpr int RIGHT_MQ = A3;

    // A4 and A5 are reserved for I2C (LiquidCrystal_I2C)

    // Trigger pins for ultrasonic sensors
    constexpr int RIGHT_US_TRIG = 5;
    constexpr int CENTER_US_TRIG = 7;
    constexpr int LEFT_US_TRIG = 9;

    // Echo pins for ultrasonic sensors
    constexpr int RIGHT_US_ECHO = 6;
    constexpr int CENTER_US_ECHO = 8;
    constexpr int LEFT_US_ECHO = 10;

    // Motor pins
    constexpr int LEFT_MOTOR = 0;
    constexpr int RIGHT_MOTOR = 1;

    // Vacuum pin
    constexpr int VACUUM = 2;
}