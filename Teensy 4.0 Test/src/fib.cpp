#include <Arduino.h>


#include <Arduino.h>

static void threadFib( int n ){

  // setup
  Serial.begin( 115200 );

  // loop
  while (1) {
    unsigned long time = measureTime( n );
    Serial.print( "Fibonacci in ");
    Serial.print( time );
    Serial.println( "microseconds." );
  }
}


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
