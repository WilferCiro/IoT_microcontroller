ESP32 Project with MQTT, Ultrasonic Sensor, Soil Moisture Sensor, and Water Pump
This project uses an ESP32 to connect to an MQTT broker, read data from an ultrasonic sensor and a soil moisture sensor, and control a water pump. The project can be used to automate the watering of plants or other tasks.

Requirements
ESP32 development board
Ultrasonic sensor
Soil moisture sensor
Water pump
USB cable
Arduino IDE
PubSubClient library
Setup
Connect the ultrasonic sensor to the ESP32 development board as follows:

Echo pin to GPIO 2
Trig pin to GPIO 0
Connect the soil moisture sensor to the ESP32 development board as follows:

VCC pin to 3.3V
GND pin to GND
SOUT pin to GPIO 3
Connect the water pump to the ESP32 development board as follows:

VCC pin to 3.3V
GND pin to GND
PWM pin to GPIO 1
Open the Arduino IDE and load the ESP32_MQTT_WaterPump.ino sketch.

Configure the MQTT broker settings in the sketch.

Upload the sketch to the ESP32 development board.

Usage
Once the sketch is uploaded, the ESP32 will connect to the MQTT broker and read data from the ultrasonic sensor and soil moisture sensor. The ESP32 will then control the water pump based on the data from the sensors.

For example, if the ultrasonic sensor detects that the water level is low, the ESP32 will turn on the water pump. If the soil moisture sensor detects that the soil is dry, the ESP32 will turn on the water pump.

Conclusion
This project shows how to use an ESP32 to connect to an MQTT broker, read data from sensors, and control a device. The project can be used to automate a variety of tasks, such as watering plants, controlling lights, or opening and closing doors.