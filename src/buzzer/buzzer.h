#ifndef BUZZER_H
#define BUZZER_H

#include <Arduino.h>

// Pin configuration for the buzzer
extern const int buzzerPin;

// Buzzer settings
extern unsigned long buzzerStartTime; // Time when the buzzer was turned on
extern const long beepDuration;		  // Duration for the beep in milliseconds
extern bool isBuzzerOn;				  // Flag to track if the buzzer is currently on

// Function prototypes
void buzzerSetup();
void buzzIfTrue(bool &shouldBuzz);

#endif // BUZZER_H