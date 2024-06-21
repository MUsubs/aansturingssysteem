#include "travel_control.hpp"

namespace asn {

TravelControl::TravelControl( MotorControl &motorControl, SteerControl &steerControl ) :
    motorControl( motorControl ), steerControl( steerControl ) {
}

void TravelControl::calculateRotation( const float cur_x, const float cur_z ) {
    float angle = acos(
        ( ( ( cur_x - prev_x ) * ( dest_x - cur_x ) ) + ( ( cur_z - prev_z ) * ( dest_z - cur_z ) ) ) /
        ( sqrt( pow( ( cur_x - prev_x ), 2 ) + pow( ( cur_z - prev_z ), 2 ) ) *
          sqrt( pow( ( dest_x - cur_x ), 2 ) + pow( ( dest_z - cur_z ), 2 ) ) ) );
    angle = angle * ( 180 / ( atan( 1 ) * 4 ) );
    steerControl.setSetpoint( angle );
    Serial.printf( "Finished calculateRotation, result = %f\n", angle );
}

void TravelControl::stop() {
    motorControl.move( motorControl.direction_t::STOP );
    steerControl.stop = true;
}

void TravelControl::newDest( const float newdest_x, const float newdest_y, const float newdest_z ) {
    dest_x = newdest_x;
    dest_z = newdest_z;
    dest_y = newdest_y;
    motorControl.move( motorControl.direction_t::FORWARD );
    vTaskDelay( 100 );
    motorControl.move( motorControl.direction_t::STOP );
    steerControl.stop = false;
}

void TravelControl::updateCurPos( const float cur_x, const float cur_y, const float cur_z ) {
    calculateRotation( cur_x, cur_z );
    if ( prev_x == cur_x && prev_z == cur_z ) {
        motorControl.move( motorControl.direction_t::BACKWARD );
        vTaskDelay( 100 );
        motorControl.move( motorControl.direction_t::STOP );
    } if ( dest_x == cur_x && dest_z == cur_z ) {
        steerControl.stop = true;
        if ( cur_y < dest_y ) {
            motorControl.move( motorControl.direction_t::UP );
        } else if ( cur_y > dest_y ) {
            motorControl.move( motorControl.direction_t::DOWN );
        } else {
            motorControl.move( motorControl.direction_t::STOP );
        }
    }
}

void TravelControl::main() {
}

}  // namespace asn

// angle = cos^-1((a_x * b_x) + (a_z * b_z) / (sqrt((a_x)^2 + (a_z)^2) *
// sqrt((b_x)^2 + (b_z)^2)))