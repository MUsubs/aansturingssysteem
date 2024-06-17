#include "directions.hpp"

void motorSetup( void *parameters ) {
    // Cast parameters to correct type
    uint8_t *pins = static_cast<uint8_t *>( parameters );
    const uint8_t pin_driver_eep = pins[0];
    const uint8_t pin_fwd1 = pins[1];
    const uint8_t pin_fwd2 = pins[2];
    const uint8_t pin_height1 = pins[3];
    const uint8_t pin_height2 = pins[4];
    const uint8_t pin_steer1 = pins[5];
    const uint8_t pin_steer2 = pins[6];
    const uint8_t pin_button = pins[7];

    // Set up serial and pins:
    pinMode( pin_driver_eep, OUTPUT );
    pinMode( pin_fwd1, OUTPUT );
    pinMode( pin_fwd2, OUTPUT );
    pinMode( pin_height1, OUTPUT );
    pinMode( pin_height2, OUTPUT );
    pinMode( pin_steer1, OUTPUT );
    pinMode( pin_steer2, OUTPUT );

    pinMode( pin_button, INPUT );

    digitalWrite( pin_driver_eep, HIGH );
    digitalWrite( pin_fwd1, LOW );
    digitalWrite( pin_fwd2, LOW );
    digitalWrite( pin_height1, LOW );
    digitalWrite( pin_height2, LOW );
    digitalWrite( pin_steer1, LOW );
    digitalWrite( pin_steer2, LOW );

    // Print start
    Serial.println("start");
}

void leftDirection( uint8_t *pins ) {
    digitalWrite( pins[5], HIGH );
    digitalWrite( pins[6], LOW );
}

void rightDirection( uint8_t *pins ) {
    digitalWrite( pins[5], LOW );
    digitalWrite( pins[6], HIGH );
}

void forwardDirection( uint8_t *pins ) {
    digitalWrite( pins[1], HIGH );
    digitalWrite( pins[2], LOW );
}

void backwardDirection( uint8_t *pins ) {
    digitalWrite( pins[1], LOW );
    digitalWrite( pins[2], HIGH );
}

void upDirection( uint8_t *pins ) {
    digitalWrite( pins[3], HIGH );
    digitalWrite( pins[4], LOW );
}

void downDirection( uint8_t *pins ) {
    digitalWrite( pins[3], LOW );
    digitalWrite( pins[4], HIGH );
}

void off( uint8_t *pins ) {
    digitalWrite( pins[1], LOW );
    digitalWrite( pins[2], LOW );
    digitalWrite( pins[3], LOW );
    digitalWrite( pins[4], LOW );
    digitalWrite( pins[5], LOW );
    digitalWrite( pins[6], LOW );
}
