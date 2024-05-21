#include <Arduino.h>

// TODO: 
// 1. lastige berekening (fibonacci, prime, etc.)
// 2. sensor uitlezen (afstand)
// 3. sensor aansturen (ledje)
// 4. motor aansturen (stappenmotor)

static void threadLight( int led_pin, int duration ){
  
  // setup: 
  pinMode( led_pin, OUTPUT );
  
  //loop
  while ( 1 ) {
    digitalWrite( led_pin, HIGH );
    delay( duration );
    digitalWrite( led_pin, LOW );
    delay( duration );
  }

}
