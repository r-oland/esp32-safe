#include "screen/screen.h"
#include "servo/servo.h"
#include "joystick/joystick.h"
#include "screen/setScreenTime/setScreenTime.h"
#include "util/global.h"
#include <Arduino.h>
#include <TM1637Display.h>
#include <cmath>

static unsigned long joystickTimeTracker = 0; // Variable to track the last time the code ran
static unsigned long displayTimeTracker = 0;  // Variable to track the last time the code ran
static bool blinkState = false;				  // Keeps track of whether the character is shown or hidden
static int activeIndex = 0;					  // Index of the active character
// Timer values
static int hours = 0;
static int hour = 0;
static int minutes = 0;
static int minute = 0;

static void updateValue(int &value, bool increase, int max)
{
	if (increase)
	{
		// Increment the value
		value = (value + 1) % max; // Wrap around to 0 after 9
	}
	else
	{
		// Decrement the value
		value = (value - 1 + max) % max; // Wrap around to 9 after 0
	}
}

void setScreenTime(String direction)
{
	// Set the segments array with the digits for display
	uint8_t data[] = {
		display.encodeDigit(hours),	  // Thousands place (hour tens)
		display.encodeDigit(hour),	  // Hundreds place (hour ones)
		display.encodeDigit(minutes), // Tens place (minute tens)
		display.encodeDigit(minute)	  // Ones place (minute ones)
	};

	if (millis() - displayTimeTracker >= 300)
	{
		// Update the last execution time
		displayTimeTracker = millis();

		blinkState = !blinkState; // Toggle the blink state

		data[1] |= 0x80; // Turn the colon on

		if (blinkState)
		{
			// Show the character
			display.setSegments(data);
		}
		else
		{
			// Clear the character at the desired position
			data[activeIndex] = 0x00;
			display.setSegments(data);
		}
	}

	// Check if 200ms have passed since the last execution
	if (millis() - joystickTimeTracker >= 200)
	{
		// Update the last execution time
		joystickTimeTracker = millis();

		// Run the code if the direction is not empty
		if (direction != "")
		{
			if ((activeIndex == 0 || activeIndex == 1 || activeIndex == 2) && direction == "RIGHT")
				activeIndex++;

			if ((activeIndex == 1 || activeIndex == 2 || activeIndex == 3) && direction == "LEFT")
				activeIndex--;

			if (direction == "UP")
			{
				if (activeIndex == 0)
					updateValue(hours, true);

				if (activeIndex == 1)
					updateValue(hour, true);

				if (activeIndex == 2)
					updateValue(minutes, true, 6);

				if (activeIndex == 3)
					updateValue(minute, true);
			}

			if (direction == "DOWN")
			{
				if (activeIndex == 0)
					updateValue(hours, false);

				if (activeIndex == 1)
					updateValue(hour, false);

				if (activeIndex == 2)
					updateValue(minutes, false, 6);

				if (activeIndex == 3)
					updateValue(minute, false);
			}
		}
	}

	bool buttonPressed = listenForButtonPress(); // Check for button press

	if (buttonPressed)
	{
		const int seconds = hours * 36000 + hour * 3600 + minutes * 600 + minute * 60;
		initiateCountdown(seconds); // Display time on screen
		toggleLock();				// Toggle the lock
	}
}