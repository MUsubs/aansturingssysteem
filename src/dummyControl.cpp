#include "dummyControl.hpp"

namespace asn {

DummyControl::DummyControl( TravelControl& travelControl ) : travelControl( travelControl ) {
}

void DummyControl::main() {
    Serial.println( "start dummy" );
    travelControl.updateCurPos( 0.2, 0.0 );
    vTaskDelay( 2000 );
    travelControl.updateCurPos( 0.4, 0.4 );
    vTaskDelay( 2000 );
    travelControl.updateCurPos( 0.5, 0.8 );
}

}  // namespace asn
