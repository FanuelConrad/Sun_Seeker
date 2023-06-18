#include "SolarModule.h"
void SolarModule::displaySolarPosition(tmElements_t time, tmElements_t date, float lat, float lon)
{

    SolarPosition savedPosition(lat, lon);
    time_t epochTime = makeTime(time);
    Serial.print(F("The sun was at an elevation of "));
    Serial.print(savedPosition.getSolarPosition(epochTime).elevation, 4);
    Serial.print(F(" and an azimuth of "));
    Serial.println(savedPosition.getSolarPosition(epochTime).azimuth, 4);

    azimuth = savedPosition.getSolarPosition(epochTime).azimuth, 4;
    elevation = savedPosition.getSolarPosition(epochTime).elevation, 4;
}