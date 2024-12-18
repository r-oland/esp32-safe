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
  joystickSetup(); // Initialize joystick (and buzzer)
  screenSetup();   // Initialize screen
  servoSetup();    // Initialize servo
}

void loop()
{
  servoLoop();  // Handle joystick behavior (and buzzer)
  screenLoop(); // Display time on screen
}