#ifndef MOTOR_HPP
#define MOTOR_HPP

#include <Arduino.h>

class Motor {
public:
    Motor(uint8_t* pins);
    void setMotor(uint8_t motor[2], bool on, bool dir);
    uint8_t steer[2];
    uint8_t speed[2];
    uint8_t depth[2];
    bool on = false;
    bool dir = false;
private:
    uint8_t* motor_pins;
    uint8_t pin_driver_eep;
};

enum direction_t {
    LEFT,
    RIGHT,
    FORWARD,
    BACKWARD,
    UP,
    DOWN
};

#endif // MOTOR_HPP
