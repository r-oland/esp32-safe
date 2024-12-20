// joystick.h
#ifndef JOYSTICK_H
#define JOYSTICK_H

#include <Arduino.h>

// Function declarations
void joystickSetup();
bool listenForButtonPress();
String listenForJoystickPositionChange();
void listenForPasscode(String direction);

#endif // JOYSTICK_H