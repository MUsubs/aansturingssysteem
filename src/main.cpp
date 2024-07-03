#include <Arduino.h>
#include <freeRTOS.h>

#include "motor.hpp"
#include "motor_control.hpp"

static uint8_t motor_pins[7] = { 22, 18, 19, 20, 21, 16, 17 };
static uint8_t button_pins[4] = { 10, 11, 12, 13 };
asn::MotorControl motor_control( motor_pins );

xTaskHandle motor_control_task_handle;

bool forward;
bool backward;
bool left;
bool right;

void motorControlTask( void* pvParameters ) {
    asn::MotorControl* mc =
        reinterpret_cast<asn::MotorControl*>( pvParameters );
    mc->main();
}

void setup() {
    // motor(driver) pins voor motor
    Serial.begin( 115200 );
    vTaskDelay( 2000 );

    forward = false;
    backward = false;
    left = false;
    right = false;

    for ( auto button_pin : button_pins ) {
        pinMode( button_pin, INPUT );
    }

    auto return_motor = xTaskCreate( motorControlTask, "MotorControl task", 2048, (void*)&motor_control, 1, &motor_control_task_handle );

    if ( return_motor !- ) {

    }
}

void loop() {
    if ( digitalRead( button_pins[0] ) ) {
        forward != forward;
        backward = false;
    }
    if ( digitalRead( button_pins[1] ) ) {
        backward != backward;
        forward = false;
    }
    if ( digitalRead( button_pins[2] ) ) {
        left != left;
        right = false;
    }
    if ( digitalRead( button_pins[3] ) ) {
        right != right;
        right = false;
    }

    // stop all
    motor_control.move( motor_control.direction_t::STOP );
    // start (again) if on
    // speed motor
    if ( forward ) {
        motor_control.move( motor_control.direction_t::FORWARD );
    } else if ( backward ) {
        motor_control.move( motor_control.direction_t::BACKWARD );
    }

    // steer motor
    if ( right ) {
        motor_control.move( motor_control.direction_t::RIGHT );
    } else if ( left ) {
        motor_control.move( motor_control.direction_t::LEFT );
    }

    vTaskDelay( 100 );
}