#include <Arduino.h>
#include <TM1637Display.h>
#include "screen/screen.h"

// Constants
static const unsigned long inactivityThreshold = 10000; // 10 seconds in milliseconds

// Variables
static unsigned long lastActivityTime = 0; // Tracks the last time activity was detected
static bool isDimmed = false;			   // Keeps track of the current brightness state

void controleBrightness(String direction)
{
	// Check if there is activity
	if (direction != "")
	{
		// Reset the inactivity timer and brightness if activity is detected
		lastActivityTime = millis();
		if (isDimmed)
		{
			display.setBrightness(0x0f); // Set to bright mode
			isDimmed = false;
		}
	}

	// Check if inactivity exceeds the threshold
	if (!isDimmed && (millis() - lastActivityTime >= inactivityThreshold))
	{
		display.setBrightness(0x00); // Dim the brightness
		isDimmed = true;
	}
}