#include <Arduino.h>

// TODO: 
// 1. lastige berekening (fibonacci, prime, etc.)
// 2. sensor uitlezen (afstand)
// 3. sensor aansturen (ledje)
// 4. motor aansturen (stappenmotor)

void setup() {
  pinMode(trigPin, OUTPUT); // Set trigger pin as output
  pinMode(echoPin, INPUT);  // Set echo pin as input
}


void loop() {
  // Trigger a sound wave
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure echo time
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance (speed of sound * time / 2)
  distance = duration * 0.034 / 2; // Adjust factor for speed of sound in your units

  // Display or store the distance measurement
  // ...
}
