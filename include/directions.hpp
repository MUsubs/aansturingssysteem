#pragma once

#include <Arduino.h>

void motorSetup(void *parameters);

void leftDirection(uint8_t *pins);
void rightDirection(uint8_t *pins);
void forwardDirection(uint8_t *pins);
void backwardDirection(uint8_t *pins);
void upDirection(uint8_t *pins);
void downDirection(uint8_t *pins);
void off(uint8_t *pins);