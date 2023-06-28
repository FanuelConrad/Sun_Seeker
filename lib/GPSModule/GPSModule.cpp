#include "GPSModule.h"

GPSModule::GPSModule(int rxPin, int txPin, uint32_t baudRate) : rxPin(rxPin), txPin(txPin), baudRate(baudRate), ss(rxPin, txPin)
{
}

void GPSModule::begin()
{
    ss.begin(baudRate);
}

bool GPSModule::isGPSModuleConnected()
{
    if (millis() > 5000 && gps.charsProcessed() < 10)
    {
        Serial.println(F("No GPS detected: check wiring."));
        while (true)
            return false;
    }
    else
    {
        Serial.println(F("GPS deteced"));
        return true;
    }
}

void GPSModule::update()
{
    while (ss.available() > 0)
    {
        if (gps.encode(ss.read()))
            break;
    }
}

bool GPSModule::isDataAvailable()
{
    return gps.location.isValid() && gps.date.isValid();
}

void GPSModule::displayLocation()
{
    Serial.print(F("Location:"));
    if (gps.location.isValid())
    {
        Serial.print(gps.location.lat(), digits);
        Serial.print(F(","));
        Serial.print(gps.location.lng(), digits);
    }
    else
    {
        Serial.print("INVALID");
    }

    Serial.print(F(" Date/Time:"));
    if (gps.date.isValid())
    {
        Serial.print(gps.date.month());
        Serial.print(F("/"));
        Serial.print(gps.date.day());
        Serial.print(F("/"));
        Serial.println(gps.date.year());
    }
    else
    {
        Serial.println(F("INVALID"));
    }
}

int GPSModule::charsProcessed()
{
    return gps.charsProcessed();
}

tmElements_t GPSModule::getTime()
{
    int second = gps.time.second(); // second
    int minute = gps.time.minute(); // minute
    int hour = gps.time.hour();     // hour
    tmElements_t someTime = {second, minute, hour, 0, gps.date.day(), gps.date.month(), CalendarYrToTm(gps.date.year())};

    return someTime;
}

tmElements_t GPSModule::getDate()
{
    int day = gps.date.day();     // day
    int month = gps.date.month(); // month
    int year = gps.date.year();   // year
    tmElements_t someDate = {0, 0, 0, 0, day, month, CalendarYrToTm(year)};
    return someDate;
}

float GPSModule::lat()
{
    return gps.location.lat();
}

float GPSModule::lon()
{
    return gps.location.lng();
}