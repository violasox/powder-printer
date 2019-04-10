#include <Arduino.h>
#include "motor_driver_test.h"
// Enables / disables all motors
#define ENABLE 2
// Resets all motors
#define RESET 3
// Sleep all motors
#define SLEEP 6

// X-axis printhead motor
#define X_M1 7
#define X_M2 8
#define X_M3 9
#define X_STEP 4
#define X_DIR 10

// Y_axis printhead motor
#define Y_M1 24
#define Y_M2 25
#define Y_M3 26
#define Y_STEP 5
#define Y_DIR 27

// Roller motor
#define ROLL_M1 20
#define ROLL_M2 19
#define ROLL_M3 18
#define ROLL_STEP 23
#define ROLL_DIR 17

// Print bed motor
#define BED_M1 16
#define BED_M2 15
#define BED_M3 14
#define BED_STEP 22
#define BED_DIR 13

// Powder well motor
#define PDR_M1 39
#define PDR_M2 38
#define PDR_M3 37
#define PDR_STEP 31
#define PDR_DIR 36

// Other stuff
#define LED_1 34
#define LED_2 33
#define BUTTON 29

void my_main() {
    pinMode(X_STEP, OUTPUT);
    pinMode(X_M1, OUTPUT);
    pinMode(X_M2, OUTPUT);
    pinMode(X_M3, OUTPUT);
    pinMode(ENABLE, OUTPUT);
    pinMode(X_DIR, OUTPUT);

    digitalWrite(X_M1, HIGH);
    digitalWrite(X_M2, HIGH);
    digitalWrite(X_M3, HIGH);
    digitalWrite(ENABLE, LOW);
    Serial.begin(9600);
    delay(1);
    Serial.println("Setup complete");
    while (true) {
        step(Direction::FORWARD);
        delay(5);
        step(Direction::BACKWARD);
        delay(5);
    }
}

void step(Direction dir) {
    if (dir == Direction::FORWARD) {
        Serial.println("Moving forward");
        digitalWrite(X_DIR, LOW);
    }
    else {
        Serial.println("Moving backward");
        digitalWrite(X_DIR, HIGH);
    }
    for (int x = 1; x < 1000; x++) {
        digitalWrite(X_STEP, HIGH);
        delay(1);
        digitalWrite(X_STEP, LOW);
        delay(1);
    }
}

