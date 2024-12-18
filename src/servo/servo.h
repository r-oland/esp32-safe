#ifndef SERVO_H
#define SERVO_H

#include <Arduino.h>
#include <ESP32Servo.h>

// Global Variables
extern Servo myservo;		 // Servo object
extern int pos;				 // Variable to store the servo position
extern bool closed;			 // Tracks direction of servo movement
extern bool lastButtonState; // Last state of the button
extern bool shouldBuzz;		 // Flag to trigger the buzzer

// Pin Definitions
extern const int switchPin; // Pin for the button
extern const int servoPin;	// Pin for the servo

// Function Prototypes
void servoSetup();
void servoLoop();

#endif // SERVO_H