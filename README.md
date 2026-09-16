###   PressureSensorLib
A lightweight C++ library for reading pressure values from hydrostatic analogue pressure sensors. This library handles voltage and current conversions, allowing for easy integration of pressure transducers (e.g., 4-20mA or 0-10V systems) into embedded projects.

###   Features
Flexible Configuration: Set custom minimum and maximum pressure ranges. 
Multiple Units: Read raw voltage, current (mA), or calculated pressure.
Sampling/Averaging: Configurable sample count to smooth out sensor noise.
Reset Functionality: Easily re-initialize the sensor state.

###   Installation
- 1.Clone this repository into your project's library folder:
git clone https://github.com/yourusername/PressureSensor.git
- 2.Include the header file in your C++ project:
#include "PressureSensor.h"

###   Hardware Setup
This library assumes the sensor is connected to an Analog-to-Digital Converter (ADC) pin. If you are using a current-loop sensor (e.g., 4-20mA), ensure you have a Shunt Resistor installed in parallel to convert the current to a measurable voltage.

###   API Reference
- Constructor
- PressureSensor(int pin, int samples)
- pin: The analog input pin connected to the sensor.
- samples: The number of readings to average per measurement (higher = smoother but slower).

## #  Method	Description
- void setParam(float minPress, float maxPress)	Sets the minimum and maximum pressure range for the sensor (e.g., 0 to 150 PSI).
- void begin()	Initializes the sensor pins and internal variables. Call this in setup().
- float readVolt()	Returns the raw voltage reading from the sensor.
- float readCurr()	Returns the calculated current (typically in mA) based on the shunt resistor value.
- float readPressure()	Returns the calculated pressure mapped to the minPress and maxPress parameters.

###   Calibration Notes
To ensure accurate readings, verify the following in your hardware setup:
- Shunt Resistor: If using a current output sensor, the readCurr function relies on the resistance value specified in your source code. Ensure this matches the physical resistor used.
- ADC Reference: Ensure your microcontroller's ADC reference voltage matches the expected logic level (e.g., 5V vs 3.3V).

###   License
This project is licensed under the MIT License - see the LICENSE file for details
