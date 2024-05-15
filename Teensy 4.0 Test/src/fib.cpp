#include <Arduino.h>

// TODO: 
// 1. lastige berekening (fibonacci, prime, etc.)
// 2. sensor uitlezen (afstand)
// 3. sensor aansturen (ledje)
// 4. motor aansturen (stappenmotor)

float fibonacci( int n ) {
  if ( n <= 1 ) {
    return n;
  }
  return fibonacci( n - 1 ) + fibonacci( n - 2 );
}

float measureTime( int n ) {
  unsigned long start = micros();
  fibonacci( n );
  unsigned long end = micros();
  return end - start;
}
