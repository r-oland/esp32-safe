// servo.cpp

#include "servo/servo.h"
#include <Arduino.h>
#include <ESP32Servo.h>
#include "buzzer/buzzer.h"
#include "util/global.h"

Servo myservo;		// Declare the servo object
static int pos = 0; // Variable to store the servo position

// Define pins
static const int servoPin = 21; // Pin D21 for the servo

void servoSetup()
{
	// Attach the servo to the defined pin
	myservo.attach(servoPin);

	// Initialize the servo position to 0 degrees
	myservo.write(0);
}

void toggleLock()
{
	shouldBuzz = true;

	if (lockClosed)
	{
		// Move servo from 0 to 180 degrees
		for (pos = 0; pos <= 180; pos += 5)
		{
			myservo.write(pos);
		}
	}
	else
	{
		// Move servo from 180 to 0 degrees
		for (pos = 180; pos >= 0; pos -= 5)
		{
			myservo.write(pos);
		}
	}

	// Toggle the direction for the next button press
	lockClosed = !lockClosed;
}