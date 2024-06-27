#include "mpu6050.hpp"

namespace asn {

Mpu6050::Mpu6050( Adafruit_MPU6050 &mpu ) : mpu( mpu ) {
}

void Mpu6050::setUpGyro() {
    byte status = mpu.begin();
    mpu.setAccelerometerRange( MPU6050_RANGE_2_G );
    mpu.setGyroRange( MPU6050_RANGE_500_DEG );
    mpu.setFilterBandwidth( MPU6050_BAND_21_HZ );
    preInterval = millis();  // may cause issue if begin() is much before the first update()
}

float Mpu6050::getCurrent_z() {
    sensors_event_t a, g, t;
    mpu.getEvent( &a, &g, &t );

    float accX = ( (float)a.acceleration.x ) / 16384.0;
    float accY = ( (float)a.acceleration.y ) / 16384.0;
    float accZ = ( (float)a.acceleration.z ) / 16384.0;
    float temp = ( t.temperature + 12412.0 ) / 340.0;
    float gyroX = ( (float)g.gyro.x ) / 65.5;
    float gyroY = ( (float)g.gyro.y ) / 65.5;
    float gyroZ = ( (float)g.gyro.z ) / 65.5;

    float sgZ = ( accZ >= 0 ) - ( accZ < 0 );
    float angleAccX = atan2( accY, sgZ * sqrt( accZ * accZ + accX * accX ) ) * 57.29578;
    float angleAccY = -atan2( accX, sqrt( accZ * accZ + accY * accY ) ) * 57.29578;

    unsigned long Tnew = millis();
    float dt = ( Tnew - preInterval ) * 1e-3;
    preInterval = Tnew;

    angleZ += gyroZ * dt;

    return angleZ;
}

float Mpu6050::getAcc_z() {
    sensors_event_t a, g, temp;
    mpu.getEvent( &a, &g, &temp );
    return a.acceleration.z;
}

}  // namespace asn