// joystick.h
#ifndef JOYSTICK_H
#define JOYSTICK_H

#include <Arduino.h>

// Pin assignments
extern const int buttonPin; // Button pin (D32)
extern const int xPin;		// Joystick X-axis pin (left-right)
extern const int yPin;		// Joystick Y-axis pin (top-bottom)

// Neutral positions for joystick
extern int xNeutral;
extern int yNeutral;

// Function declarations
void joystickSetup();
bool listenForButtonPress();
String listenForJoystickPositionChange();

#endif // JOYSTICK_H