#ifndef SOLAR_MODULE_H
#define SOLAR_MODULE_H

#include <SolarPosition.h>
#include <TimeLib.h>

class SolarModule
{
public:
    float azimuth=0;
    float elevation=0;

    void displaySolarPosition(tmElements_t time, tmElements_t date, float lat, float lon);
};

#endif