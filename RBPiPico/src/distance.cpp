#include "distance.hpp"

void threadDistance(const uint8_t trig_pin, const uint8_t echo_pin)
{
    // setup
    pinMode(trig_pin, OUTPUT); // Set trigger pin as output
    pinMode(echo_pin, INPUT);  // Set echo pin as input

    // loop
    while (1)
    {
        // Trigger a sound wave
        digitalWrite(trig_pin, LOW);
        delayMicroseconds(2);
        digitalWrite(trig_pin, HIGH);
        delayMicroseconds(10);
        digitalWrite(trig_pin, LOW);

        // Measure echo time
        uint32_t duration = pulseIn(echo_pin, HIGH);

        // Calculate distance (speed of sound * time / 2)
        uint32_t distance = duration * 0.034 / 2; // Adjust factor for speed of sound in your units
        Serial.println(distance);
    }
}