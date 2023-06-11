#include <Arduino.h>
//#include <TinyGPSPlus.h>
//#include <SoftwareSerial.h>
//#include <SolarPosition.h>
#include <GPSModule.h>
#include <SolarModule.h>

static const int RXPin = 13, TXPin = 27;
static const uint32_t GPSBaud = 9600;

GPSModule gpsModule(RXPin,TXPin,GPSBaud);
SolarModule solarModule;

// number of decimal digits to print
const uint8_t digits = 3;

// A solar position structure to demonstrate strong complete positions
//SolarPosition currentLocation(gps.location.lat(), gps.location.lng());

void setup()
{
  Serial.begin(115200);
  gpsModule.begin();
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