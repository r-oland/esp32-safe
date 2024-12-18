#ifndef JOYSTICK_H
#define JOYSTICK_H

#include <Arduino.h>

// Pin Definition
extern const int buttonPin; // Pin for the button

// Global Variables
extern bool lastButtonState; // Tracks the previous state of the button
extern bool buttonPressed;	 // Tracks if the button was pressed once

// Function Prototypes
void joystickSetup();
bool listenForButtonPress();

#endif // JOYSTICK_H