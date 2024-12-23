#include <Arduino.h>
#include <Preferences.h>

extern Preferences preferences; // Declare the preferences object
extern bool shouldBuzz;			// Flag to trigger the buzzer
extern String mode;				// Current display mode
extern int countdownTime;		// Variable to store the countdown time