#pragma once

#include <Arduino.h>

void touchTest(bool &on, const uint8_t pin_button, const uint8_t pin_steer1, const uint8_t pin_height1, const uint8_t pin_fwd2);

void threadMotor(void *parameters);