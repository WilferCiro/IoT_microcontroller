#ifndef MQTT_H
#define MQTT_H
#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>

class MQTTCom {
private:
  int pin;

public:
  bool isConnected();
  void reconnect();
  void setupWifi();
  void pubish(int sensor1, int sensor2, int water);
};

#endif