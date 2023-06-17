#include <Arduino.h>
#include <GPSModule.h>
#include <SolarModule.h>
#include <MPU6050Module.h>
#include "servo_utils.h"

static const int RXPin = 13, TXPin = 27;
static const uint32_t GPSBaud = 9600;

//Create objects for accelerometer and GPS
GPSModule gpsModule(RXPin,TXPin,GPSBaud);
SolarModule solarModule;
MPU6050Module mpu6050Module;

// number of decimal digits to print
const uint8_t digits = 3;

// A solar position structure to demonstrate strong complete positions
//SolarPosition currentLocation(gps.location.lat(), gps.location.lng());


//Constants for the solar panel setup
const float MAX_PAN_ANGLE =180.0;
const float MAX_TILT_ANGLE=90.0;

//Variables to store current orientation and GPS location
float currentPanAngle=0.0;
float currentTiltAngle=0.0;
float desiredPanAngle=0.0;
float desiredTiltAngle=0.0;
float gpsLatitude=0.0;
float gpsLongitude=0.0;

//Function to read accelerometer data and update the current orientation
void updateOrientation(){
  
}

void setup()
{
  Serial.begin(115200);
  gpsModule.begin();
  mpu6050Module.setupMPU6050();
}

void loop()
{
  gpsModule.update();
  if(gpsModule.isDataAvailable()){
    gpsModule.displayLocation();
    solarModule.displaySolarPosition(gpsModule.getTime(),gpsModule.getDate(),gpsModule.lat(),gpsModule.lon());
  }
  

  if (millis() > 5000 && gpsModule.charsProcessed() < 10)
  {
    Serial.println(F("No GPS detected: check wiring."));
    while (true)
      ;
  }
}