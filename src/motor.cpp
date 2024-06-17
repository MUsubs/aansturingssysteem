#include "motor.hpp"

Motor::Motor(uint8_t* pins) : 
    motorpins(pins),
    // Cast parameters to correct type
    pin_driver_eep(motorpins[0]),
    pin_fwd1(motorpins[1]),
    pin_fwd2(motorpins[2]),
    pin_height1(motorpins[3]),
    pin_height2(motorpins[4]),
    pin_steer1(motorpins[5]),
    pin_steer2(motorpins[6])
    {
    // Set up serial and pins:
    pinMode(pin_driver_eep, OUTPUT);
    pinMode(pin_fwd1, OUTPUT);
    pinMode(pin_fwd2, OUTPUT);
    pinMode(pin_height1, OUTPUT);
    pinMode(pin_height2, OUTPUT);
    pinMode(pin_steer1, OUTPUT);
    pinMode(pin_steer2, OUTPUT);

    digitalWrite(pin_driver_eep, HIGH);
    digitalWrite(pin_fwd1, LOW);
    digitalWrite(pin_fwd2, LOW);
    digitalWrite(pin_height1, LOW);
    digitalWrite(pin_height2, LOW);
    digitalWrite(pin_steer1, LOW);
    digitalWrite(pin_steer2, LOW);
}

void Motor::leftDirection(){
    digitalWrite( pin_steer1, HIGH );
    digitalWrite( pin_steer2, LOW );
}

void Motor::rightDirection(){
    digitalWrite( pin_steer1, LOW );
    digitalWrite( pin_steer2, HIGH );
}

void Motor::forwardDirection(){
    digitalWrite( pin_fwd1, HIGH );
    digitalWrite( pin_fwd2, LOW );
}

void Motor::backwardDirection(){
    digitalWrite( pin_fwd1, LOW );
    digitalWrite( pin_fwd2, HIGH );
}

void Motor::upDirection(){
    digitalWrite( pin_height1, HIGH );
    digitalWrite( pin_height2, LOW );
}

void Motor::downDirection(){
    digitalWrite( pin_height1, LOW );
    digitalWrite( pin_height2, HIGH );
}

void Motor::off(){
    digitalWrite( pin_fwd1, LOW );
    digitalWrite( pin_fwd2, LOW );
    digitalWrite( pin_height1, LOW );
    digitalWrite( pin_height2, LOW );
    digitalWrite( pin_steer1, LOW );
    digitalWrite( pin_steer2, LOW );
}