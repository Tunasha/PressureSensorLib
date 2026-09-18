
/* This is simple example to read all data from hydrostatic liquid pressure sensor and print them out to serial bus. 
Authors: Tunasha, Babatunde Adg
*/
#include <PressureSensorLib.h>

PressureSensor sensor(A0, 10);  // Pin A0, average over 10 samples
unsigned long previousMillis = 0;

void setup() {
  Serial.begin(9600);
  sensor.setParam(0.0, 500.0);  // set according to your sensor minPress, maxPress (in your unit, e.g. bar)
                               // Only use a shunt Resistor of 150ohms for the sensor connection for error-free readings
  sensor.begin(); 
}

void loop() {
  float voltage  = sensor.readVolt();       // read volatge
  float current  = sensor.readCurr();       // read Current
  float pressure = sensor.readPressure();  // read pressure

  // prints out readings every 1second
  if (millis() - previousMillis >= 1000) {
    Serial.println("volt " + String(voltage));
    Serial.println("curr " + String(current,4));
    Serial.println("pressure " + String(pressure,2));
    previousMillis = millis();
  }
}
