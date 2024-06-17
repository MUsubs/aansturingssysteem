#ifndef MOTOR_HPP
#define MOTOR_HPP

#include <Arduino.h>

class Motor {
public:
    Motor(uint8_t* pins);
    void leftDirection();
    void rightDirection();
    void forwardDirection();
    void backwardDirection();
    void upDirection();
    void downDirection();
    void off();
private:
    uint8_t* motorpins;
    uint8_t pin_driver_eep;
    uint8_t pin_fwd1;
    uint8_t pin_fwd2;
    uint8_t pin_height1;
    uint8_t pin_height2;
    uint8_t pin_steer1;
    uint8_t pin_steer2;
};

#endif // MOTOR_HPP
