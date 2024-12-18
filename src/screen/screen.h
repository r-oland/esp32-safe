#ifndef SCREEN_H
#define SCREEN_H

#include <Arduino.h>
#include <TM1637Display.h>

// Module connection pins (Digital Pins)
#define CLK 19
#define DIO 18

// Global variables and constants
extern TM1637Display display;			   // Display object
extern unsigned long screenPreviousMillis; // Store the last time update was done
extern const long interval;				   // Interval at which to update (1 second)

// Function prototypes
void screenSetup();
void screenLoop();

#endif // SCREEN_H