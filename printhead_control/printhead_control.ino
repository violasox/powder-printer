byte printHeadPins[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

void setup() {
    // Set the printhead pins to output mode
    for (int i = 0; i < 12; i++) {
        pinMode(printHeadPins[i], OUTPUT);
    }
}

void loop() {
    // Put code to run here
}

// Function to spray ink. Bytes for the nozzles come from the file created with Processing
void spray_ink(byte lower_nozzles, byte upper_nozzles) {
    for (int i = 0; i < 8; i++) {
        byte mask = 1 << i;
        if (lower_nozzles & mask) {
            digitalWrite(printHeadPins[i], HIGH);
            delayMicroseconds(5);
            digitalWrite(printHeadPins[i], LOW);
            delayMicroseconds(1);
        }
    }
    for (int i = 0; i < 4; i++) {
        byte mask = 1 << i;
        if (upper_nozzles << 3 & mask) {
            digitalWrite(printHeadPins[i+8], HIGH);
            delayMicroseconds(5);
            digitalWrite(printHeadPins[i], LOW);
            delayMicroseconds(1);
        }
    }

    // According to Pwdr, this prevents printhead nozzle burnout
    delayMicroseconds(450);
}

