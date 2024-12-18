#include "screen/screen.h"
#include "servo/servo.h"
#include "util/global.h"
#include <Arduino.h>
#include <TM1637Display.h>

// Module connection pins (Digital Pins)
#define CLK 19
#define DIO 18

TM1637Display display(CLK, DIO); // Initialize the display object

unsigned long screenPreviousMillis = 0; // Store last time update was done
const long interval = 1000;				// Interval at which to update (1 second)

void screenSetup()
{
	display.setBrightness(0x0f); // Set brightness to maximum
}

int timeInSeconds = 0;

void screenLoop()
{
	if (displayMode == "IDLE")
	{
		// idle = 00:00
		display.showNumberDecEx(0, 0b01000000, true);
	}

	if (displayMode == "COUNTDOWN")
	{
		static int totalSeconds = timeInSeconds; // 1 hour = 3600 seconds

		// Calculate minutes and seconds
		int minutes = totalSeconds / 60;
		int seconds = totalSeconds % 60;

		// Display time in MM:SS format
		int timeToDisplay = minutes * 100 + seconds;			  // Combine MM and SS for display
		display.showNumberDecEx(timeToDisplay, 0b01000000, true); // Display colon using 0b01000000

		// Use millis() to update every second
		unsigned long currentMillis = millis();
		if (currentMillis - screenPreviousMillis >= interval)
		{
			screenPreviousMillis = currentMillis; // Save the last update time
			totalSeconds--;						  // Decrease total time by 1 second

			if (totalSeconds == 0)
			{
				displayMode = "IDLE";
				toggleLock(); // Toggle the lock
			}
		}
	}
}

void initiateCountdown(int seconds)
{
	displayMode = "COUNTDOWN";
	timeInSeconds = seconds;
}