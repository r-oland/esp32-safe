// servo.cpp

#include "servo/servo.h"
#include <Arduino.h>
#include <ESP32Servo.h>
#include "buzzer/buzzer.h"
#include "joystick/joystick.h"

Servo myservo;		// Declare the servo object
int pos = 0;		// Variable to store the servo position
bool closed = true; // Tracks direction of servo movement

// Define pins
const int servoPin = 21; // Pin D21 for the servo

void servoSetup()
{
	// Attach the servo to the defined pin
	myservo.attach(servoPin);

	// Initialize the servo position to 0 degrees
	myservo.write(0);
}

bool shouldBuzz = false;

void servoLoop()
{
	buzzIfTrue(shouldBuzz); // bzz

	bool pressed = listenForButtonPress();

	if (pressed)
	{
		shouldBuzz = true;

		if (closed)
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
		closed = !closed;
	}
}