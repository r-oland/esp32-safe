// servo.h

#ifndef SERVO_H
#define SERVO_H

#include <ESP32Servo.h>

// Define joystick pins
extern const int switchPin; // Pin D32 for the button
extern const int servoPin;	// Pin D21 for the servo

// Function declarations
void servoSetup();
void servoLoop();

#endif