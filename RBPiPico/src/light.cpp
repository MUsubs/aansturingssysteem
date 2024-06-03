#include "light.hpp"

void threadLight( int led_pin, int duration ){
  
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