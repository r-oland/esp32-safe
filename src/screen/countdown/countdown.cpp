#include "screen/screen.h"
#include "servo/servo.h"
#include "util/global.h"
#include <Arduino.h>
#include <TM1637Display.h>

static unsigned long screenPreviousMillis = 0; // Store last time update was done
static const long interval = 1000;			   // Interval at which to update (1 second)

void countdown()
{
	// Use millis() to update every second
	unsigned long currentMillis = millis();
	if (currentMillis - screenPreviousMillis >= interval)
	{
		screenPreviousMillis = currentMillis; // Save the last update time

		if (countdownTime > 0)
		{
			countdownTime--; // Decrease total time by 1 second
		}

		// Calculate hours, minutes, and seconds
		int hours = countdownTime / 3600;
		int minutes = (countdownTime % 3600) / 60;
		int seconds = countdownTime % 60;

		// Display time in HH:MM or MM:SS format based on remaining time
		int timeToDisplay;
		if (hours > 0)
		{
			timeToDisplay = hours * 100 + minutes; // Display HH:MM
		}
		else
		{
			timeToDisplay = minutes * 100 + seconds; // Display MM:SS
		}

		// Show the time on the display with a blinking colon
		display.showNumberDecEx(timeToDisplay, 0b01000000, true); // Colon = 0b01000000

		// Handle countdown completion
		if (countdownTime == 0)
		{
			displayMode = "IDLE";
			toggleLock(); // Toggle the lock
		}
	}
}