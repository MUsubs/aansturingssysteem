#include "dummyControl.hpp"

namespace asn {

DummyControl::DummyControl( MotorControl& motorControl ) : motorControl( motorControl ){
}

void DummyControl::main() {
    motorControl.move( MotorControl::direction_t::FORWARD );
    delay( 1000 );
    motorControl.move( MotorControl::direction_t::STOP );
    delay( 1000 );
    motorControl.move( MotorControl::direction_t::BACKWARD );
    delay( 1000 );
    motorControl.move( MotorControl::direction_t::STOP );
    delay( 1000 );
    motorControl.move( MotorControl::direction_t::LEFT );
    delay( 1000 );
    motorControl.move( MotorControl::direction_t::STOP );
    delay( 1000 );
    motorControl.move( MotorControl::direction_t::RIGHT );
    delay( 1000 );
    motorControl.move( MotorControl::direction_t::STOP );
}

}  // namespace asn
