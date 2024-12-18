#include "buzzer.h"
#include "util/global.h"
#include <Arduino.h>

const int buzzerPin = 5; // Pin D5 for the buzzer

void buzzerSetup()
{
	pinMode(buzzerPin, OUTPUT); // Configure buzzer pin as output
}

unsigned long buzzerStartTime = 0; // Time when the buzzer was turned on
const long beepDuration = 100;	   // Duration for the beep in milliseconds
bool isBuzzerOn = false;		   // Flag to track if the buzzer is currently on

void buzzerLoop() // Pass by reference using &
{
	unsigned long currentMillis = millis(); // Get current time

	// If the buzzer has not been turned on yet, turn it on
	if (shouldBuzz && !isBuzzerOn)
	{
		digitalWrite(buzzerPin, HIGH);	 // Turn the buzzer on
		isBuzzerOn = true;				 // Mark the buzzer as turned on
		buzzerStartTime = currentMillis; // Record the time when the buzzer was turned on
	}

	// If 100ms has passed, turn off the buzzer
	if ((currentMillis - buzzerStartTime >= beepDuration) && isBuzzerOn)
	{
		digitalWrite(buzzerPin, LOW); // Turn the buzzer off
		shouldBuzz = false;			  // Reset the shouldBuzz flag
		isBuzzerOn = false;			  // Mark the buzzer as turned off
	}
}