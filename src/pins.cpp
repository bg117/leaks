#include <pins.h>

bool isActive(int pin)
{
    return digitalRead(pin) == HIGH;
}