#include <Arduino.h>
#include <FreeRTOS_TEENSY4.h>
// #include "Memory test.cpp"
#include "distance.hpp"
#include "fib.hpp"
#include "light.hpp"
#include "motor.hpp"

// PAS OP: geen pwm op pinnen 6, 7, 8, 9
// bij gebruik van run-time stats (configGENERATE_RUN_TIME_STATS), verandert timer3


// TODO: 
// 1. lastige berekening (fibonacci, prime, etc.) - measure time
// 2. sensor uitlezen (afstand)
// 3. sensor aansturen (ledje)
// 4. motor aansturen (motor)
void setup(){

    // led pin voor light
    // on board led
    // const uint8_t led_pin = 13;

    // // afstandssensor pinnen voor distance
    // const uint8_t echo_pin = 14;
    // const uint8_t trig_pin = 15;

    // // motor(driver) pins voor motor
    // static uint8_t motor_pins[8] = { 22, 21, 20, 19, 18, 4, 5, 8 };

    Serial.begin(9600);
    Serial.print("hello?");
    // Memory
    // test_memory_speed();
    // threadMotor((void*)motor_pins);
    threadFib(30);
    // threadLight(led_pin, 50);
    // threadDistance(trig_pin, echo_pin);
}

void loop(){}
