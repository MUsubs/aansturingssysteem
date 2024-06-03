#include <Arduino.h>

// declare pin numbers:
const int pin_driver_eep = 22;

const int pin_fwd1 = 21;
const int pin_fwd2 = 20;

const int pin_height1 = 19;
const int pin_height2 = 18;

const int pin_steer1 = 4;
const int pin_steer2 = 5;

const int pin_touch = 8;

void touchTest();
bool on = false;

void setup()
{
    // Set up serial and pins:
    Serial.begin(115200);
    
    pinMode(pin_driver_eep, OUTPUT);
    pinMode(pin_fwd1, OUTPUT);
    pinMode(pin_fwd2, OUTPUT);
    pinMode(pin_height1, OUTPUT);
    pinMode(pin_height2, OUTPUT);
    pinMode(pin_steer1, OUTPUT);
    pinMode(pin_steer2, OUTPUT);

    pinMode(pin_touch, INPUT);

    digitalWrite(pin_driver_eep, HIGH);
    digitalWrite(pin_fwd1, LOW);
    digitalWrite(pin_fwd2, LOW);
    digitalWrite(pin_height1, LOW);
    digitalWrite(pin_height2, LOW);
    digitalWrite(pin_steer1, LOW);
    digitalWrite(pin_steer2, LOW);

    // Print start
    Serial.print("start");
}

void loop()
{
    touchTest();
    delay(50);
}

// Test function for demo.
void touchTest()
{
    // All motors on if touch switch on.
    on = !on ? digitalRead(pin_touch) : on;
    PinStatus status = on ? HIGH : LOW;

    digitalWrite(pin_steer1, status);
    digitalWrite(pin_height1, status);
    digitalWrite(pin_fwd2, status);
}
