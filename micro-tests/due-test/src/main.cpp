#include <Arduino.h>

const int PWM_A = 3;
const int DIRECTION_A = 9;
// const int

void setup()
{
    pinMode(PWM_A, OUTPUT);
    pinMode(DIRECTION_A, OUTPUT);

    Serial.begin(9600);
    Serial.print("Motor doet het ofzo? ");
}

void loop()
{
    analogWrite(PWM_A, 255);
    digitalWrite(DIRECTION_A, HIGH);
    delay(2000);

    analogWrite(PWM_A, 0);
    delay(2000);

    analogWrite(PWM_A, 255);
    digitalWrite(DIRECTION_A, LOW);
    delay(2000);

    analogWrite(PWM_A, 0);
    delay(2000);
}
