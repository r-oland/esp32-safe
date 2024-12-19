#include "screen/screen.h"
#include "joystick/joystick.h"
#include "screen/countdown/countdown.h"
#include "screen/setScreenTime/setScreenTime.h"
#include "util/global.h"
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
	displayMode = "COUNTDOWN";
	countdownTime = seconds;
}