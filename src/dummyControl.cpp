#include "dummyControl.hpp"

namespace asn {

DummyControl::DummyControl( MotorControl& motorControl ) : motorControl( motorControl ){
}

void DummyControl::main() {
    // Serial.println("start dummy");
    for(;;){
        motorControl.move( MotorControl::direction_t::FORWARD );
        vTaskDelay(1000);
        motorControl.move( MotorControl::direction_t::STOP );
        vTaskDelay( 1000 );
        motorControl.move( MotorControl::direction_t::BACKWARD );
        vTaskDelay( 1000 );
        motorControl.move( MotorControl::direction_t::STOP );
        vTaskDelay( 1000 );
        motorControl.move( MotorControl::direction_t::LEFT );
        vTaskDelay( 1000 );
        motorControl.move( MotorControl::direction_t::STOP );
        vTaskDelay( 1000 );
        motorControl.move( MotorControl::direction_t::RIGHT );
        vTaskDelay( 1000 );
        motorControl.move( MotorControl::direction_t::STOP );
        vTaskDelay( 1000 );
        motorControl.move( MotorControl::direction_t::UP );
        vTaskDelay( 1000 );
        motorControl.move( MotorControl::direction_t::STOP);
        vTaskDelay( 1000 );
        motorControl.move( MotorControl::direction_t::DOWN );
        vTaskDelay( 1000 );
        motorControl.move( MotorControl::direction_t::STOP );
        vTaskDelay( 1000 );
        // Serial.println("end cycle");
    }
}

}  // namespace asn
