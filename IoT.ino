#include "ultrasonic.h"
#include "humidity.h"
#include "mqtt.h"

#define MAX_DISTANCE_CM 25

UltrasonicSensor sensorUS(5, 18);
HumiditySensor sensorH1(T0);
HumiditySensor sensorH2(T1);
MQTTCom mqttServer;

// Configure the wakeup pin
const int wakeupPin = 12;
// The amount of time to sleep in seconds
const int sleepTime = 21600;  // 6 hours in seconds

void setup() {
  pinMode(wakeupPin, INPUT);
  Serial.begin(115200);
}

void loop() {
  // when wake up, need to reconect
  while(!mqttServer.isConnected()) {
    mqttServer.setupWifi();
    delay(100);
    mqttServer.reconnect();
    delay(100);
  }

  // Read the ultrasonic sensor, and calculate the water percent in the recype
  int distanceWater = sensorUS.getDistance();
  int percentWater = MAX_DISTANCE_CM - ((distanceWater * 100) / MAX_DISTANCE_CM);

  delay(100);

  int humidity1 = sensorH1.getHumidity();
  int humidity2 = sensorH2.getHumidity();

  delay(1000);

  mqttServer.pubish(humidity1, humidity2, percentWater);

  // Go to sleep
  esp_sleep_enable_timer_wakeup(sleepTime * 1000000);
  esp_deep_sleep_start();
}