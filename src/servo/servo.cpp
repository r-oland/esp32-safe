#include "servo/servo.h"
#include <Arduino.h>
#include <ESP32Servo.h>
#include "buzzer/buzzer.h"
#include "util/global.h"

Servo myservo; // Declare the servo object

static const int open = 35;	  // Constant to represent the open position
static const int locked = 62; // Constant to represent the locked position
static const int detachTime = 500;

static int pos = open; // Variable to store the servo position

// Define pins
static const int servoPin = 21; // Pin D21 for the servo

void servoSetup()
{
	// Attach the servo to the defined pin
	myservo.attach(servoPin);

	// Initialize the servo position to 0 degrees
	myservo.write(open);

	unsigned long startTime = millis(); // Record the current time
	while (millis() - startTime < detachTime)
	{
		// Wait for 1000ms without blocking other operations
	}

	myservo.detach(); // Turn off the servo to save power
}

void toggleLock()
{
	shouldBuzz = true;

	myservo.attach(servoPin); // Reattach servo before moving

	if (lockClosed)
	{
		// Move servo from open to locked position
		for (pos = open; pos <= locked; pos += 5)
		{
			myservo.write(pos);
		}
	}
	else
	{
		// Move servo from locked to open position
		for (pos = locked; pos >= open; pos -= 5)
		{
			myservo.write(pos);
		}
	}

	// Record the start time for the 2000ms delay
	unsigned long startTime = millis();
	while (millis() - startTime < detachTime)
	{
		// Wait for 1000ms without blocking other operations
	}

	myservo.detach(); // Turn off the servo to save power

	// Toggle the direction for the next button press
	lockClosed = !lockClosed;
}