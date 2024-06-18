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
        motor.setMotor(motor.steer, true, true);
        delay(50);
    }
    else if(round(gyro.getCurrent_z()) > gyro.getSetpoint()){
        Serial.println(" right ");
        motor.setMotor(motor.steer, true, false);
        delay(50);
    }
    if (digitalRead(button_pins[0]) == HIGH){
        motor.setMotor(motor.speed, true, true);
        delay(50);
        motor.setMotor(motor.speed, false, true);
    }
    if (digitalRead(button_pins[1]) == HIGH){
        motor.setMotor(motor.speed, true, false);
        delay(50);
        motor.setMotor(motor.speed, false, false);
    }
    if (digitalRead(button_pins[2]) == HIGH){
        motor.setMotor(motor.depth, true, true);
        delay(50);
        motor.setMotor(motor.depth, false, true);
    }
    if (digitalRead(button_pins[3]) == HIGH){
        motor.setMotor(motor.depth, true, false);
        delay(50);
        motor.setMotor(motor.depth, false, false);
    }
}
