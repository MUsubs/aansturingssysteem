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
  int n_fib  = 1;
  //5 sec wachten om tijd te geven aan de python script
  while (n_fib > 25) {
    Serial.print("hellooo1!!!");
    float fib_n = fibonacci(n_fib);
    
    Serial.print(fib_n);
    Serial.print(",");
    unsigned long currentTime = millis() / 1000;
    Serial.print( currentTime );
    float temp = tempmonGetTemp();
    Serial.print(",");
    Serial.println(temp);
    n_fib += 1;
    delay(1000);// 0.5 sec wachten tussen meting

  }
  // while(n_fib < 0){
  //   float fib_n = fibonacci(n_fib);
  //   Serial.print(fib_n);
  //   Serial.print(",");
  //   unsigned long currentTime = millis() / 1000;
  //   Serial.print( currentTime );
  //   float temp = tempmonGetTemp();
  //   Serial.print(",");
  //   Serial.println(temp);
  //   n_fib -= 1;
  //   delay(1000);// 0.5 sec wachten tussen meting
  // }
}
