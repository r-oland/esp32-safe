#include "servo/servo.h"
#include <Arduino.h>
#include <ESP32Servo.h>
#include "buzzer/buzzer.h"
#include "util/global.h"
#include "util/pref.h"

Servo myservo; // Declare the servo object

static const int open = 35;	  // Constant to represent the open position
static const int locked = 62; // Constant to represent the locked position
static const int detachTime = 750;

static int pos = open; // Variable to store the servo position

// Define pins
static const int servoPin = 21; // Pin D21 for the servo

void servoSetup()
{
	bool lockOpen = getIsLockOpen();

	// Attach the servo to the defined pin
	myservo.attach(servoPin);

	// Initialize the servo position
	if (lockOpen)
		myservo.write(open);
	if (!lockOpen)
		myservo.write(locked);

	unsigned long startTime = millis(); // Record the current time
	while (millis() - startTime < detachTime)
	{
		// Wait for detachTime without blocking other operations
	}

	myservo.detach(); // Turn off the servo to save power
}

void toggleLock()
{
	bool lockOpen = getIsLockOpen();
	myservo.attach(servoPin); // Reattach servo before moving

	shouldBuzz = true;

	if (!lockOpen)
	{
		myservo.write(open);
	}
	else
	{
		myservo.write(locked);
	}

	unsigned long startTime = millis(); // Record the start time
	while (millis() - startTime < detachTime)
	{
		// Wait for detachTime without blocking other operations
	}

	myservo.detach(); // Turn off the servo to save power

	// Toggle the direction for the next button press
	toggleLockOpen(lockOpen);
}