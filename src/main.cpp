#include <Arduino.h>
#include "buzzer/buzzer.h"
#include "joystick/joystick.h"
#include "screen/screen.h"
#include "servo/servo.h"

void setup()
{
  // Begin serial communication
  Serial.begin(115200);

  buzzerSetup();   // Initialize the buzzer
  joystickSetup(); // Initialize joystick
  screenSetup();   // Initialize screen
  servoSetup();    // Initialize servo
}

unsigned long lastExecutionTime = 0; // Variable to track the last time the code ran

void loop()
{
  screenLoop(); // Handle screen behavior
  buzzerLoop(); // Handle buzzer behavior

  String direction = listenForJoystickPositionChange(); // Check for joystick position change

  // Check if 250ms have passed since the last execution
  if (millis() - lastExecutionTime >= 250)
  {
    // Update the last execution time
    lastExecutionTime = millis();

    // Run the code if the direction is not empty
    if (direction != "")
    {
      Serial.println(direction);
    }
  }

  bool buttonPressed = listenForButtonPress(); // Check for button press

  if (buttonPressed)
  {
    initiateCountdown(60); // Display time on screen
    toggleLock();          // Toggle the lock
  }
}