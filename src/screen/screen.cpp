#include "screen/screen.h"
#include "joystick/joystick.h"
#include "screen/countdown/countdown.h"
#include "screen/setScreenTime/setScreenTime.h"
#include "util/global.h"
#include "util/pref.h"
#include <Arduino.h>
#include <TM1637Display.h>

// Module connection pins (Digital Pins)
#define CLK 19
#define DIO 18

TM1637Display display(CLK, DIO); // Initialize the display object

void screenSetup()
{
	display.setBrightness(0x0f); // Set brightness to maximum
}

void initiateCountdown(int seconds)
{
	mode = "COUNTDOWN";
	countdownTime = seconds;
	setCountdownPref(seconds);
}

void displayOpenMessage()
{
	display.clear();

	// Custom segment definitions for "OPEN"
	uint8_t openMessage[] = {
		0x3F, // O
		0x73, // P
		0x79, // E
		0x37  // N
	};

	// Display "OPEN"
	display.setSegments(openMessage);
}