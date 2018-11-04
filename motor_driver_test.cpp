#include <Arduino.h>
#include "motor_driver_test.h"
#define STEP 0
#define MS1 1
#define MS2 2
#define MS3 3
#define ENABLE 4
#define DIRECTION 5

void my_main() {
    pinMode(STEP, OUTPUT);
    pinMode(MS1, OUTPUT);
    pinMode(MS2, OUTPUT);
    pinMode(MS3, OUTPUT);
    pinMode(ENABLE, OUTPUT);
    pinMode(DIRECTION, OUTPUT);
    digitalWrite(MS1, HIGH);
    digitalWrite(MS2, HIGH);
    digitalWrite(MS3, HIGH);
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
        digitalWrite(DIRECTION, LOW);
    }
    else {
        Serial.println("Moving backward");
        digitalWrite(DIRECTION, HIGH);
    }
    for (int x = 1; x < 1000; x++) {
        digitalWrite(STEP, HIGH);
        delay(1);
        digitalWrite(STEP, LOW);
        delay(1);
    }
}

