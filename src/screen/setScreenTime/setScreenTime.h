#ifndef SET_SCREEN_TIME_H
#define SET_SCREEN_TIME_H

#include <Arduino.h>

// Function to update a value with optional increase or decrease behavior
static void updateValue(int &value, bool increase, int max = 10);

// Function to handle setting the screen time based on joystick direction
void setScreenTime(String direction);

#endif // SET_SCREEN_TIME_H