#include "screen/screen.h"
#include "servo/servo.h"
#include "joystick/joystick.h"
#include "screen/countdown/countdown.h"
#include "screen/setScreenTime/setScreenTime.h"
#include "screen/controleBrightness/controleBrightness.h"
#include "util/global.h"
#include <Arduino.h>
#include <TM1637Display.h>

void controleLoop()
{
	String direction = listenForJoystickPositionChange(); // Check for joystick position change
	controleBrightness(direction);

	if (mode == "IDLE" && direction != "")
	{
		mode = "SET_TIME";
	}

	//
	// STATES
	//

	if (mode == "IDLE")
	{
		// idle = 00:00
		display.showNumberDecEx(0, 0b01000000, true);
	}

	if (mode == "COUNTDOWN")
	{
		countdown();
		if (direction != "")
			listenForPasscode(direction);
	}

	if (mode == "SET_TIME")
	{
		setScreenTime(direction);
	}

	if (mode == "UNLOCKED")
	{
		displayOpenMessage();
		toggleLock(); // Toggle the lock

		delay(2000);

		mode = "IDLE";
	}
}