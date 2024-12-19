#include "screen/screen.h"
#include "joystick/joystick.h"
#include "screen/countdown/countdown.h"
#include "screen/setScreenTime/setScreenTime.h"
#include "util/global.h"
#include <Arduino.h>
#include <TM1637Display.h>

void controleLoop()
{
	String direction = listenForJoystickPositionChange(); // Check for joystick position change

	if (displayMode == "IDLE" && direction != "")
	{
		displayMode = "SET_TIME";
	}

	//
	// STATES
	//

	if (displayMode == "IDLE")
	{
		// idle = 00:00
		display.showNumberDecEx(0, 0b01000000, true);
	}

	if (displayMode == "COUNTDOWN")
	{
		countdown();
	}

	if (displayMode == "SET_TIME")
	{
		setScreenTime(direction);
	}
}