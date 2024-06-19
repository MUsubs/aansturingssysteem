#ifndef R2D2_DUMMY_CONTROL_HPP
#define R2D2_DUMMY_CONTROL_HPP

#include <Arduino.h>
#include "motor_control.hpp"

namespace asn {

class DummyControl {
public:
    DummyControl( MotorControl& motorControl );
    void main();

private:
    MotorControl& motorControl;
};

}  // namespace asn

#endif  // R2D2_DUMMY_CONTROL_HPP