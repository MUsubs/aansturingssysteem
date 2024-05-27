#include <Arduino.h>
#include <FreeRTOS_TEENSY4.h>

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
xTaskHandle thread_simple;

void simple_task(void* pvParameters){  
    //loop
    configASSERT( ( ( uint32_t ) pvParameters ) == 1 );
    for(;;) {
        digitalWrite( 13, HIGH );
        vTaskDelay( 500 );
        digitalWrite( 13, LOW );
        vTaskDelay( 500 );
  }
}

xTaskHandle thread_talk;

void talking_task(void* pvParameters){
    configASSERT( ( ( uint32_t ) pvParameters ) == 1);

    for(;;){
        Serial.println( "here" );
        vTaskDelay( 1000 );
    }
}



xTaskHandle thread_motor_handle;
char c;
void setup(){

    // led pin voor light
    // on board led
    // const uint8_t led_pin = 13;

    // // afstandssensor pinnen voor distance
    // const uint8_t echo_pin = 14;
    // const uint8_t trig_pin = 15;

    // // motor(driver) pins voor motor
    // static uint8_t motor_pins[8] = { 22, 21, 20, 19, 18, 4, 5, 8 };

    Serial.begin(115200);
    pinMode( 13, OUTPUT );
    
    //threadMotor(pin_driver_eep, pin_fwd1, pin_fwd2, pin_height1, pin_height2, pin_steer1, pin_steer2, pin_button);
    //threadFib(30);
    //threadLight(led_pin, 50);
    //threadDistance(trig_pin, echo_pin);

    // xTaskCreate(threadDistance, "distance", 2000, NULL,   );
    // xTaskCreate(threadFib, "fibonacci", 20000, NULL);
    // xTaskCreate(threadLight, "light", 1000, NULL);

    // threadMotor( (void*)motor_pins );
    while (!Serial) {
        ;
    }
    delay(2000);
    // auto task_return = xTaskCreate( threadMotor, "MotorControl", 10000, (void*)&motor_pins, 1, &thread_motor_handle);
    Serial.println("Before task creating\n");
    auto blep = xTaskCreate(simple_task, "Simple", 5000, (void*) 1, 1, &thread_simple);
    auto blop = xTaskCreate(talking_task, "Talk", 5000, (void*) 1, 1, &thread_talk);
    // vTaskStartScheduler();
    if (blep == pdPASS) {
        vTaskDelete(thread_simple);
        Serial.println("Blep yes\n");
    }else{
         Serial.println("Blep no\n");
    }
    // if (task_return == pdPASS) {
    //     c = 'Y';
    // }
    // else {
    //     c = 'N';
    // }
}

void loop(){
    // Serial.printf("Bonjour!\n");
    // Serial.printf("%c", c);
}


// TO DO:
// - start 4 threads.

