#include <Arduino.h>

static void threadMotor( const uint8_t pin_driver_eep, const uint8_t pin_fwd1, const uint8_t pin_fwd2,
  const uint8_t pin_height1, const uint8_t pin_height2, const uint8_t pin_steer1, const uint8_t pin_steer2, const uint8_t pin_touch ) {
  // Set up serial and pins:
  Serial.begin(115200);
  pinMode( pin_driver_eep, OUTPUT );
  pinMode( pin_fwd1, OUTPUT );
  pinMode( pin_fwd2, OUTPUT );
  pinMode( pin_height1, OUTPUT );
  pinMode( pin_height2, OUTPUT );
  pinMode( pin_steer1, OUTPUT );
  pinMode( pin_steer2, OUTPUT );

  pinMode( pin_touch, INPUT );

  digitalWrite( pin_driver_eep, HIGH );
  digitalWrite( pin_fwd1, LOW );
  digitalWrite( pin_fwd2, LOW );
  digitalWrite( pin_height1, LOW );
  digitalWrite( pin_height2, LOW );
  digitalWrite( pin_steer1, LOW );
  digitalWrite( pin_steer2, LOW );

  bool on = false;

  // Print start
  Serial.print( "start" );

  while ( 1 ){
    touchTest( on, pin_touch, pin_steer1, pin_height1, pin_fwd2 );
    delay( 50 );
  }
}


// Test function for demo.
void touchTest( bool& on, const uint8_t pin_touch, const uint8_t pin_steer1, const uint8_t pin_height1, const uint8_t pin_fwd2) {
//All motors on if touch switch on.
  if ( digitalRead( pin_touch ) ) {
    if ( on ) {
      on = false;
    } else if (!on) {
      on = true;
    }
  }

  if ( on ) {
    digitalWrite( pin_steer1, HIGH );
    digitalWrite( pin_height1, HIGH );
    digitalWrite( pin_fwd2, HIGH );
  }
  if ( !on ) {
    digitalWrite( pin_steer1, LOW );
    digitalWrite( pin_height1, LOW );
    digitalWrite( pin_fwd2, LOW );
  }
}
