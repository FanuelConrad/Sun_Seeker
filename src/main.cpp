#include <Arduino.h>
#include <TinyGPSPlus.h>
#include <SoftwareSerial.h>
#include <SolarPosition.h>

static const int RXPin = 13, TXPin = 27;
static const uint32_t GPSBaud = 9600;

// The TinyGPSPlus object
TinyGPSPlus gps;

SoftwareSerial ss(RXPin, TXPin);

void displayInfo()
{
  Serial.print(F("Location: "));
  if (gps.location.isValid())
  {
    Serial.print(gps.location.lat(), 6);
    Serial.print(F(","));
    Serial.print(gps.location.lng(), 6);
  }
  else
  {
    Serial.print(F("INVALID"));
  }

  Serial.print(F(" Date/Time: "));
  if (gps.date.isValid())
  {
    Serial.print(gps.date.month());
    Serial.print(F("/"));
    Serial.print(gps.date.day());
    Serial.print(F("/"));
    Serial.print(gps.date.year());
  }
  else
  {
    Serial.print(F("INVALID"));
  }
}

// number of decimal digits to print
const uint8_t digits = 3;

// A solar position structure to demonstrate strong complete positions
SolarPosition currentLocation(gps.location.lat(), gps.location.lng());

void setup()
{
  Serial.begin(115200);
  ss.begin(GPSBaud);

  // SolarPosition::setTimeProvider(gps.time.age());
  //  obtain a complete current position
}

void loop()
{
  while (ss.available() > 0)
    if (gps.encode(ss.read()))
    {
      displayInfo();
      // create a fixed UNIX time to test fixed time method
      int someS = gps.time.second(); // second
      int someM = gps.time.minute(); // minute
      int someH = gps.time.hour();   // hour
      int someD = gps.date.day();    // day
      int someMo = gps.date.month(); // month
      int someY = gps.date.year();   // year
      tmElements_t someTime = {someS, someM, someH, 0, someD, someMo, CalendarYrToTm(someY)};
      time_t someEpochTime = makeTime(someTime);
      Serial.print(F("The sun was at an elevation of "));
      Serial.print(currentLocation.getSolarPosition(someEpochTime).elevation, 4);
      Serial.print(F(" and an azimuth of "));
      Serial.println(currentLocation.getSolarPosition(someEpochTime).azimuth, 4);
    }

  if (millis() > 5000 && gps.charsProcessed() < 10)
  {
    Serial.println(F("No GPS detected: check wiring."));
    while (true)
      ;
  }

  /*savedPosition = calculateSolarPosition(0, gps.location.lat() * DEG_TO_RAD, gps.location.lng() * DEG_TO_RAD);
    Serial.print(F("The sun was at an elevation of "));
    Serial.print(savedPosition.elevation * RAD_TO_DEG, 4);
    Serial.print(F(" and an azimuth of "));
    Serial.println(savedPosition.azimuth * RAD_TO_DEG, 4);*/
}