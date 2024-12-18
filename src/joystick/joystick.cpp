// joystick.cpp
#include "joystick.h"
#include <Arduino.h>

const int buttonPin = 32; // Pin D32 for the button

void joystickSetup()
{
	// Configure the button pin
	pinMode(buttonPin, INPUT_PULLUP); // Button with pull-up resistor
}

bool lastButtonState = HIGH; // Start with the button not pressed (HIGH for pull-up)
bool buttonPressed = false;	 // Keeps track of the "pressed once" state

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