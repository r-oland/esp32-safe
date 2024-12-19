#include <Arduino.h>
#include "buzzer/buzzer.h"
#include "joystick/joystick.h"
#include "screen/screen.h"
#include "servo/servo.h"
#include "controle/controle.h"

void setup()
{
  // Begin serial communication
  Serial.begin(115200);

  buzzerSetup();   // Initialize the buzzer
  joystickSetup(); // Initialize joystick
  screenSetup();   // Initialize screen
  servoSetup();    // Initialize servo
}

void loop()
{
  controleLoop(); // Handle controle behavior
  buzzerLoop();   // Handle buzzer behavior
}