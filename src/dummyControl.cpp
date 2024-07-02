#include "dummyControl.hpp"

namespace asn {

DummyControl::DummyControl( TravelControl& travel_control ) : travel_control( travel_control ) {
}

void DummyControl::main() {
    Serial.println( "start dummy" );

    // for (;;) {
    //     motor_control.move( motor_control.direction_t::LEFT);
    //     vTaskDelay( 5000 );
    //     motor_control.move( motor_control.direction_t::STOP);
    //     vTaskDelay( 500 );
    //     motor_control.move( motor_control.direction_t::RIGHT);
    //     vTaskDelay( 5000 );
    //     motor_control.move( motor_control.direction_t::STOP);
    //     vTaskDelay( 500 );
    //     motor_control.move( motor_control.direction_t::FORWARD);
    //     vTaskDelay( 5000 );
    //     motor_control.move( motor_control.direction_t::STOP);
    //     vTaskDelay( 500 );
    //     motor_control.move( motor_control.direction_t::BACKWARD);
    //     vTaskDelay( 5000 );
    //     motor_control.move( motor_control.direction_t::STOP);
    //     vTaskDelay( 500 );
    // }



    // // for(;;){
    travel_control.updateCurPos( 0.0, 0.0, 0.0 );
    vTaskDelay( 1000 );
    travel_control.newDest( 1.0, 0.0, 1.0 );
    vTaskDelay( 1000 );
    travel_control.updateCurPos( 0.5, 0.0, 0.0 );
    // // vTaskDelay( 1000 );
    // // travel_control.updateCurPos( 0.5, 0.0, 0.0 );
    // // vTaskDelay ( 1000 );
    // // travel_control.updateCurPos( 0.5, 0.0, 0.3);
    // // vTaskDelay ( 1000 );
    // // travel_control.updateCurPos(1.0, 0.0, 1.0);
    // // vTaskDelay(1000);
    // // travel_control.updateCurPos(1.0, 1.0, 1.0);
    // // vTaskDelay(1000);
    // // travel_control.stop();
    // // travel_control.stop();
}

}  // namespace asn
