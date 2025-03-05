#pragma once

/**
 * Setup the pins.
 *
 * This function initializes the pins used in the program.
 * It sets the pins as input or output.
 *
 * The pins are defined in the pins.h file.
 */
void setupPins();

/**
 * Test the output devices.
 * 
 * This function tests the output devices, such as the LEDs, motors, and vacuum.
 */
void testOutputs();