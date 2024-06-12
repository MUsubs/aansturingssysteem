#include "fib.hpp"

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

void threadFib( int n ){

  // setup
  Serial.println( "start fib" );

  // loop
  while (1) {
    unsigned long time = measureTime( n );
    Serial.print( "Fibonacci in ");
    Serial.print( time );
    Serial.println( " microseconds." );
    float temperature = (float)temperatureRead();
    Serial.print("Onboard temperature: ");
    Serial.print(temperature);
    Serial.println(" °C");
  }
}