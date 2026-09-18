
/* 
MIT License

Copyright (c) 2026 Babatunde Adg

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

This is simple example to read all data from hydrostatic liquid pressure sensor and print them out to serial bus. 
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
