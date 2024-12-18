#include <Arduino.h>
#include "buzzer/buzzer.h"
#include "joystick/joystick.h"
#include "screen/screen.h"
#include "servo/servo.h"

void setup()
{
  // Begin serial communication
  Serial.begin(9600);

  buzzerSetup();   // Initialize the buzzer
  joystickSetup(); // Initialize joystick
  screenSetup();   // Initialize screen
  servoSetup();    // Initialize servo
}

void loop()
{
  screenLoop(); // Display time on screen
  servoLoop();  // Handle servo behavior
}