#include "GPSModule.h"

GPSModule::GPSModule(int rxPin, int txPin, uint32_t baudRate) : rxPin(rxPin), txPin(txPin), baudRate(baudRate), ss(rxPin, txPin)
{
}

void GPSModule::begin()
{
    Serial.begin(115200);
    ss.begin(baudRate);
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

    Serial.print(F("Date/Time:"));
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

int GPSModule::charsProcessed()
{
    return gps.charsProcessed();
}

tmElements_t GPSModule::getTime()
{
    int someS = gps.time.second(); // second
    int someM = gps.time.minute(); // minute
    int someH = gps.time.hour();   // hour
    tmElements_t someTime = {someS, someM, someH, 0, gps.date.day(), gps.date.month(), CalendarYrToTm(gps.date.year())};

    return someTime;
}

tmElements_t GPSModule::getDate()
{
    int someD = gps.date.day();    // day
    int someMo = gps.date.month(); // month
    int someY = gps.date.year();   // year
    tmElements_t someDate = {0, 0, 0, 0, someD, someMo, CalendarYrToTm(someY)};
    return someDate;
}