#include <Arduino.h>

extern bool lockClosed;	   // Tracks direction of servo movement
extern bool shouldBuzz;	   // Flag to trigger the buzzer
extern String displayMode; // Current display mode