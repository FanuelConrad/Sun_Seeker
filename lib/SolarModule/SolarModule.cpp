#include "SolarModule.h"
void SolarModule::displaySolarPosition(tmElements_t time, tmElements_t date, float lat, float lon)
{

    SolarPosition savedPosition(lat, lon);
    time_t epochTime = makeTime(time);

    azimuth = savedPosition.getSolarPosition(epochTime).azimuth, 4;
    elevation = savedPosition.getSolarPosition(epochTime).elevation, 4;

    Serial.println((String) "The sun was at an elevation of " + elevation + " and an azimuth of " + azimuth);
}