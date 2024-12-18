#ifndef SCREEN_H
#define SCREEN_H

#include <TM1637Display.h>

// Module connection pins (Digital Pins)
#define CLK 19
#define DIO 18

extern TM1637Display display; // Declare the display object

// Function prototypes for screen behavior
void screenSetup();
void screenLoop();

#endif // SCREEN_H