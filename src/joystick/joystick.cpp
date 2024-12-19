// joystick.cpp
#include "joystick.h"
#include <Arduino.h>

static const int buttonPin = 32; // Pin D32 for the button
static const int xPin = 34;		 // Joystick X-axis pin (left-right)
static const int yPin = 35;		 // Joystick Y-axis pin (top-bottom)

static int xNeutral;
static int yNeutral;

void joystickSetup()
{
	// Configure the button pin
	pinMode(buttonPin, INPUT_PULLUP); // Button with pull-up resistor

	// Read the initial state of the button
	xNeutral = analogRead(xPin);
	yNeutral = analogRead(yPin);
}

static bool lastButtonState = HIGH; // Start with the button not pressed (HIGH for pull-up)
static bool buttonPressed = false;	// Keeps track of the "pressed once" state

bool listenForButtonPress()
{
	// Read the current state of the button
	bool currentButtonState = digitalRead(buttonPin);

	// Check for state change from HIGH to LOW (button press)
	if (currentButtonState == LOW && lastButtonState == HIGH && !buttonPressed)
	{
		buttonPressed = true;				  // Mark as "pressed once"
		lastButtonState = currentButtonState; // Update last state
		return true;						  // Button was just pressed
	}

	// Reset the "pressed once" state if the button is released
	if (currentButtonState == HIGH && buttonPressed)
	{
		buttonPressed = false; // Reset the pressed state
	}

	lastButtonState = currentButtonState; // Update the last state
	return false;						  // Button is not being pressed for the first time
}

static bool joystickMoved = false; // Keeps track of whether the joystick has moved to an extreme position
static String lastDirection = "";  // Keeps track of the last detected direction

String listenForJoystickPositionChange()
{
	// Threshold values for detecting extreme positions
	int leftThreshold = xNeutral - 1000;
	int rightThreshold = xNeutral + 1200;
	int topThreshold = yNeutral - 500;
	int bottomThreshold = yNeutral + 500;

	// Read the analog values of the joystick axes
	int xValue = analogRead(xPin);
	int yValue = analogRead(yPin);

	// Check for the extreme positions on the X-axis (left or right)
	if (xValue < leftThreshold && !joystickMoved)
	{
		joystickMoved = true;
		lastDirection = "LEFT";
		return "LEFT"; // Log the position once
	}
	if (xValue > rightThreshold && !joystickMoved)
	{
		joystickMoved = true;
		lastDirection = "RIGHT";
		return "RIGHT"; // Log the position once
	}

	// Check for the extreme positions on the Y-axis (top or bottom)
	if (yValue < topThreshold && !joystickMoved)
	{
		joystickMoved = true;
		lastDirection = "UP";
		return "UP"; // Log the position once
	}
	if (yValue > bottomThreshold && !joystickMoved)
	{
		joystickMoved = true;
		lastDirection = "DOWN";
		return "DOWN"; // Log the position once
	}

	// Reset the joystick moved flag when the joystick is no longer in an extreme position
	if (xValue >= leftThreshold && xValue <= rightThreshold && yValue >= topThreshold && yValue <= bottomThreshold)
	{
		joystickMoved = false; // Allow logging again after returning to the neutral position
		lastDirection = "";
	}

	return lastDirection; // Return the last direction if no new extreme position is detected
}