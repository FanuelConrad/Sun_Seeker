#include <Arduino.h>
#include <GPSModule.h>
#include <SolarModule.h>
#include <MPU6050Module.h>
#include "servo_utils.h"

static const int RXPin = 13, TXPin = 27;
static const uint32_t GPSBaud = 9600;

// Create objects for accelerometer and GPS
GPSModule gpsModule(RXPin, TXPin, GPSBaud);
SolarModule solarModule;
MPU6050Module mpu6050Module;

// number of decimal digits to print
const uint8_t digits = 3;

// A solar position structure to demonstrate strong complete positions
// SolarPosition currentLocation(gps.location.lat(), gps.location.lng());

// Constants for the solar panel setup
const float MAX_PAN_ANGLE = 180.0;
const float MAX_TILT_ANGLE = 90.0;

// Variables to store current orientation and GPS location
float currentPanAngle = 0.0;
float currentTiltAngle = 0.0;
float desiredPanAngle = 0.0;
float desiredTiltAngle = 0.0;
float gpsLatitude = 0.0;
float gpsLongitude = 0.0;

// Function to read accelerometer data and update the current orientation
void updateOrientation()
{
  // Map accelerometer values to pan and tilt angles
  currentPanAngle = map(mpu6050Module.position.x, -180, 180, 0, MAX_PAN_ANGLE);
  Serial.println((String) "Current pan angle:" + currentPanAngle);
  currentTiltAngle = map(mpu6050Module.position.y, -180, 180, 0, MAX_TILT_ANGLE);
  Serial.println((String) "Current tilt angle:" + currentTiltAngle);
}

// Function to calculate desired pan and tilt angles based on GPS location
void calculateDesiredAngles()
{
  desiredPanAngle = solarModule.azimuth;
  Serial.println((String) "Desired pan angle:" + desiredPanAngle);
  desiredTiltAngle = solarModule.elevation;
  Serial.println((String) "Desired tilt angle:" + desiredTiltAngle);
}

// Function to update the solar panel orientation based on the desired angles
void updateSolarPanelOrientation()
{
  // Calculate the deviation between desired and current angles
  float panDeviation = desiredPanAngle - currentPanAngle;
  Serial.println((String) "Pan deviation:" + panDeviation);
  float tiltDeviation = desiredTiltAngle - currentTiltAngle;
  Serial.println((String) "Tilt deviation:" + tiltDeviation);

  // Calculate servo position based on deviation
  int panServoPosition = map(panDeviation, -180, 180, 0, 180);
  Serial.println((String) "Pan servo position:" + panServoPosition);
  int tiltServoPosition = map(tiltDeviation, -90, 90, 0, 180);
  Serial.println((String) "Tilt servo position:" + tiltServoPosition);

  // Set the servo position
  setServoPositions(panServoPosition, tiltServoPosition);
}

void setup()
{
  Serial.begin(115200);
  gpsModule.begin();
  mpu6050Module.setupMPU6050();
  initializeServos();
}

void loop()
{
  if (gpsModule.isGPSModuleConnected())
  {
    gpsModule.update();
    if (gpsModule.isDataAvailable())
    {
      gpsModule.displayLocation();
      mpu6050Module.readSample();
      solarModule.displaySolarPosition(gpsModule.getTime(), gpsModule.getDate(), gpsModule.lat(), gpsModule.lon());
    }
  }

  updateOrientation();
  calculateDesiredAngles();
  updateSolarPanelOrientation();
}