#include <Arduino.h>

bool lockClosed = true; // Tracks direction of servo movement
bool shouldBuzz = true; // Set to true to trigger the buzzer on start
String mode = "IDLE";	// Current display mode
int countdownTime = 0;	// Variable to store the countdown time