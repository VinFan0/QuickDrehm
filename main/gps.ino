// GPS Module
// Teensy Flight Controller - QuickDrehm
// Author: Ryan Beck

/*
  FieldMarker utilizes the Bietian BE-880 GPS/Compass module

*/
#include <TinyGPSpp.h>
#include <QMC5883LCompass.h> // Includes Wire.h

static const int GPS_RXPin = 0, GPS_TXPin = 1;  // Hardware serial
#define gpsSerial Serial1
static const uint32_t GPSBaud = 38400;

TinyGPSPlus gps;

void gpsInit() {
  gpsSerial.begin(GPSBaud); // Hardware Serial for GPS UART
  
}

void getGPSData(gpsReadings_t *gps_readings) {

}