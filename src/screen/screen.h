#ifndef SCREEN_SETUP_H
#define SCREEN_SETUP_H

#include <TM1637Display.h>

// Module connection pins (Digital Pins)
#define CLK 19
#define DIO 18

extern TM1637Display display; // Declare the display object

// Function declarations
void screenSetup();
void initiateCountdown(int seconds);
void displayOpenMessage();

#endif // SCREEN_SETUP_H