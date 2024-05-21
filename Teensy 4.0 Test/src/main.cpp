#include <Arduino.h>
#include <FreeRTOS_TEENSY4.h>

// PAS OP: geen pwm op pinnen 6, 7, 8, 9
// bij gebruik van run-time stats (configGENERATE_RUN_TIME_STATS), verandert timer3


// TODO: 
// 1. lastige berekening (fibonacci, prime, etc.) - measure time
// 2. sensor uitlezen (afstand)
// 3. sensor aansturen (ledje)
// 4. motor aansturen (motor)


// led pin voor light
const uint8_t led_pin = 13;

// afstandssensor pinnen voor distance
const uint8_t echo_pin = 14;
const uint8_t trig_pin = 15;


// motor(driver) pins voor motor
const uint8_t pin_driver_eep = 22;
const uint8_t pin_fwd1 = 21;
const uint8_t pin_fwd2 = 20;
const uint8_t pin_height1 = 19;
const uint8_t pin_height2 = 18;
const uint8_t pin_steer1 = 4;
const uint8_t pin_steer2 = 5;


// TO DO:
// - start 4 threads.

