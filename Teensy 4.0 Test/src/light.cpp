#include <Arduino.h>

// TODO: 
// 1. lastige berekening (fibonacci, prime, etc.)
// 2. sensor uitlezen (afstand)
// 3. sensor aansturen (ledje)
// 4. motor aansturen (stappenmotor)

void blinkLight( int pin, int duration ) {
  digitalWrite( pin, HIGH );
  delay( duration );
  digitalWrite( pin, LOW );
}