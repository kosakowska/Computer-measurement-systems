//by Małgorzata Kosakowska and Michał Ptak
/* 
 Elektronika i telekomunikacja
 * Projekt KSP
  zrodła:
  VL53L0X Distance Sensor
  by Amir Mohammad Shojaee @ Electropeak
*/

#include "Adafruit_VL53L0X.h"
 
Adafruit_VL53L0X lox = Adafruit_VL53L0X(); //initialization of functions to sensor
 
void setup() {
  Serial.begin(115200); //serial port and baudrate
  
  // available serial port
  while (! Serial) {
    delay(1);
  }
  
  if (!lox.begin()) {
    Serial.println(F("Failed to boot VL53L0X")); //in case of error
    while(1);
  }
  // power 
  Serial.println(F("VL53L0X API Simple Ranging example\n\n")); 
}
 
 
void loop() {
  VL53L0X_RangingMeasurementData_t measure; //variable with measure
 
  Serial.print("Reading a measurement... ");
  lox.rangingTest(&measure, false); // turn off debug
 
  if (measure.RangeStatus != 4) {  // reading distance
    Serial.print("Distance (mm): "); Serial.println(measure.RangeMilliMeter);
  } else {
    Serial.println(" out of range ");
  }
 
  delay(500); //distance between measures
}
