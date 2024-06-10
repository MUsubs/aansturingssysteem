#include "motor.hpp"

// Test function for demo.
void touchTest(bool &on, const uint8_t pin_button, const uint8_t pin_steer1, const uint8_t pin_height1, const uint8_t pin_fwd2)
{
   if ( digitalRead( pin_button ) ) {
    on = !on;
  }

  if ( on ) {
    digitalWrite( pin_steer1, HIGH );
    digitalWrite( pin_height1, HIGH );
    digitalWrite( pin_fwd2, HIGH );
  }
  if ( !on ) {
    digitalWrite( pin_steer1, LOW );
    digitalWrite( pin_height1, LOW );
    digitalWrite( pin_fwd2, LOW );
  }
}

void threadMotor(void *parameters)
{
    // Cast parameters to correct type
    uint8_t *pins = static_cast<uint8_t *>(parameters);
    const uint8_t pin_driver_eep = pins[0];
    const uint8_t pin_fwd1 = pins[1];
    const uint8_t pin_fwd2 = pins[2];
    const uint8_t pin_height1 = pins[3];
    const uint8_t pin_height2 = pins[4];
    const uint8_t pin_steer1 = pins[5];
    const uint8_t pin_steer2 = pins[6];
    const uint8_t pin_button = pins[7];

    // Set up serial and pins:
    pinMode(pin_driver_eep, OUTPUT);
    pinMode(pin_fwd1, OUTPUT);
    pinMode(pin_fwd2, OUTPUT);
    pinMode(pin_height1, OUTPUT);
    pinMode(pin_height2, OUTPUT);
    pinMode(pin_steer1, OUTPUT);
    pinMode(pin_steer2, OUTPUT);

    pinMode(pin_button, INPUT);

    digitalWrite(pin_driver_eep, HIGH);
    digitalWrite(pin_fwd1, LOW);
    digitalWrite(pin_fwd2, LOW);
    digitalWrite(pin_height1, LOW);
    digitalWrite(pin_height2, LOW);
    digitalWrite(pin_steer1, LOW);
    digitalWrite(pin_steer2, LOW);

    bool on = false;

    // Print start
    Serial.println("start");

    for (;;)
    {
        touchTest(on, pin_button, pin_steer1, pin_height1, pin_fwd2);
        delay(50);
    }
}