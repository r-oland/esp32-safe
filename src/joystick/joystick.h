// joystick.h
#ifndef JOYSTICK_H
#define JOYSTICK_H

#include <Arduino.h>

// Function declarations
void joystickSetup();
bool listenForButtonPress();
String listenForJoystickPositionChange();

#endif // JOYSTICK_H