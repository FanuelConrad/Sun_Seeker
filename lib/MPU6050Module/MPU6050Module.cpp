#include "MPU6050Module.h"
#include "Angle.h"

MPU6050Module::MPU6050Module()
{
}

void MPU6050Module::setupMPU6050()
{
    // Try to initialize
    if (!mpu.begin())
    {
        Serial.println("Failed to find MPU6050 chip");
        while (1)
        {
            delay(10);
        }
    }
    Serial.println("MPU6050 found!");

    // set accelerometer range to +-8G
    mpu.setAccelerometerRange(MPU6050_RANGE_8_G);

    // set gyro range to +- 500 deg/s
    mpu.setGyroRange(MPU6050_RANGE_500_DEG);

    // set filer bandwidth to 21 Hz
    mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

    delay(100);
}

angle MPU6050Module::calculateAccelerometerAngles()
{
    angle accelerometer;

    /*Get new sensor events with the readings*/
    sensors_event_t a, g, temp;
    mpu.getEvent(&a, &g, &temp);
    accelerometer.x = (asinf(a.acceleration.x / 9.81));
    accelerometer.y = (atan2f(a.acceleration.y, a.acceleration.z));
    accelerometer.z = ((a.acceleration.z / 9.81));

    return accelerometer;
}

angle MPU6050Module::calculateGyroscopeAngles(unsigned long sampleMicros)
{
    angle gyroscope;

    /*Get new sensor events with the readings*/
    sensors_event_t a, g, temp;
    mpu.getEvent(&a, &g, &temp);
    gyroscope.x = g.gyro.x * sampleMicros / 1000000;
    gyroscope.y = g.gyro.y * sampleMicros / 1000000;
    gyroscope.z = g.gyro.z * sampleMicros / 1000000;

    return gyroscope;
}

float MPU6050Module::getTemperature()
{
    sensors_event_t a, g, temp;
    mpu.getEvent(&a, &g, &temp);
    float temperature = temp.temperature;

    return temperature;
}

void MPU6050Module::detectPitch(angle gyroscope, angle accelerometer)
{
    position.x = 0.98 * (position.x + degrees(gyroscope.x)) + 0.02 * degrees(accelerometer.x);
}

double MPU6050Module::getPitch()
{
    return position.x;
}

void MPU6050Module::detectRoll(angle gyroscope, angle accelerometer)
{
    position.y = 0.98 * (position.y + degrees(gyroscope.y)) + 0.02 * degrees(accelerometer.y);
}

double MPU6050Module::getRoll()
{
    return position.y;
}

bool MPU6050Module::readSample()
{
    unsigned long sampleMicros = (lastSampleMicros > 0) ? micros() - lastSampleMicros : 0;
    lastSampleMicros = micros();

    angle accelerometer = calculateAccelerometerAngles();
    angle gyroscope = calculateGyroscopeAngles(sampleMicros);

    detectPitch(gyroscope, accelerometer);
    detectRoll(gyroscope, accelerometer);

    return true;
}