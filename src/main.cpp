#include <Arduino.h>

#include "mpu6050.hpp"
#include "motor.hpp"

static uint8_t motor_pins[7] = { 22, 21, 20, 19, 18, 12, 13 };
static uint8_t button_pins[4] = { 16, 17, 26, 27 };
Motor motor( motor_pins );
MPU6050 mpu( Wire );
Kalman kalmanFilter;
Mpu6050 gyro( mpu, kalmanFilter);

void setup(){
    // motor(driver) pins voor motor
    Wire.begin();
    gyro.setGyroUp();
    Serial.begin(115200);
    adc_init();
    adc_set_temp_sensor_enabled (true);
    adc_select_input(4);
}

void loop(){
    Serial.print("graden: " + String(round(gyro.getCurrent_z())));
    if(round(gyro.getCurrent_z()) < gyro.getSetpoint()){
        Serial.println(" left ");
        motor.leftDirection();
        delay(50);
    }
    else if(round(gyro.getCurrent_z()) > gyro.getSetpoint()){
        Serial.println(" right ");
        motor.rightDirection();
        delay(50);
    }
    if (digitalRead(button_pins[0]) == HIGH){
        motor.forwardDirection();
        delay(50);
        motor.off();
    }
    if (digitalRead(button_pins[1]) == HIGH){
        motor.backwardDirection();
        delay(50);
        motor.off();
    }
    if (digitalRead(button_pins[2]) == HIGH){
        motor.upDirection();
        delay(50);
        motor.off();
    }
    if (digitalRead(button_pins[3]) == HIGH){
        motor.downDirection();
        delay(50);
        motor.off();
    }
}
