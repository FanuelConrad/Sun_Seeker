#ifndef MPU6050_MODULE_H
#define MPU6050_MODULE_H

#include <Arduino.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include "Angle.h"

class MPU6050Module
{
public:
    angle position;

    unsigned long lastSampleMicros = 0;
    unsigned long lastPrintMillis = 0;

#define INTERVAL_MS_PRINT 1000

    Adafruit_MPU6050 mpu;

    void setupMPU6050();
    angle calculateAccelerometerAngles();
    angle calculateGyroscopeAngles(unsigned long sampleMicros);
    float getTemperature();
    void detectPitch(angle gyroscope, angle accelerometer);
    double getPitch();
    void detectRoll(angle gyroscope, angle accelerometer);
    double getRoll();
    bool readSample();
};

#endif