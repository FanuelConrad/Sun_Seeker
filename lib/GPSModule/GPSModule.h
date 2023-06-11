#ifndef GPS_MODULE_H
#define GPS_MODULE_H

#include <Arduino.h>
#include <TinyGPSPlus.h>
#include <SoftwareSerial.h>
#include <TimeLib.h>

class GPSModule
{
public:
    GPSModule(int rxPin, int txPin, uint32_t baudRate);
    void begin();
    void update();
    bool isDataAvailable();
    void displayLocation();
    int charsProcessed();
    tmElements_t getTime();
    tmElements_t getDate();

private:
    static const uint8_t digits = 3;
    int rxPin;
    int txPin;
    uint32_t baudRate;
    TinyGPSPlus gps;
    SoftwareSerial ss;
};

#endif