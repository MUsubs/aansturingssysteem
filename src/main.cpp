#include <Arduino.h>

#include "mpu6050.hpp"
#include "motor.hpp"

static uint8_t motor_pins[7] = { 22, 21, 20, 19, 18, 4, 5 };
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
    
    Serial.println("Motor control start");
    motor.forwardDirection();
    delay(1000);
    motor.upDirection();
    delay(1000);
    motor.off();
}

void loop(){
    Serial.print("graden: " + String(round(gyro.getCurrent_z())));
    if(round(gyro.getCurrent_z()) < gyro.getSetpoint()){
        Serial.println(" left ");
        motor.upDirection();
        delay(50);
    }
    else if(round(gyro.getCurrent_z()) > gyro.getSetpoint()){
        Serial.println(" right ");
        motor.forwardDirection();
        delay(50);
    }
    else{
        Serial.println(" off");
        motor.off();
        delay(50);
    }
}