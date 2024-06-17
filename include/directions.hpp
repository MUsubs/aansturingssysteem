#pragma once

#include <Arduino.h>

void touchTest(bool &on, const uint8_t pin_button, const uint8_t pin_steer1, const uint8_t pin_height1, const uint8_t pin_fwd2);

void threadMotor(void *parameters);

void leftDirection(uint8_t *pins);
void rightDirection(uint8_t *pins);
void forwardDirection(uint8_t *pins);
void backwardDirection(uint8_t *pins);
void upDirection(uint8_t *pins);
void downDirection(uint8_t *pins);
void off(uint8_t *pins);