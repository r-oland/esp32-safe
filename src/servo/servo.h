#ifndef SERVO_H
#define SERVO_H

#include <Arduino.h>
#include <ESP32Servo.h>

// Global Variables
extern Servo myservo;		 // Servo object
extern int pos;				 // Variable to store the servo position
extern bool lastButtonState; // Last state of the button

// Pin Definitions
extern const int switchPin; // Pin for the button
extern const int servoPin;	// Pin for the servo

// Function Prototypes
void servoSetup();
void toggleLock();

#endif // SERVO_H