#include <Arduino.h>

bool lockClosed = true;		 // Tracks direction of servo movement
bool shouldBuzz = true;		 // Set to true to trigger the buzzer on start
String displayMode = "IDLE"; // Current display mode