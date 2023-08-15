#include <ArduinoJson.h>
#include "mqtt.h"

const char* ssid = "REPLACE_WITH_YOUR_SSID";
const char* password = "REPLACE_WITH_YOUR_PASSWORD";
const char* mqtt_server = "YOUR_MQTT_BROKER_IP_ADDRESS";

WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
char msg[50];
int value = 0;

void MQTTCom::setupWifi() {
  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  client.setServer(mqtt_server, 1883);
  // client.setCallback(callback);
}

bool MQTTCom::isConnected() {
  return client.connected();
}

void MQTTCom::reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("ESP8266Client")) {
      Serial.println("connected");
      // Subscribe
      client.subscribe("esp32/output");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void MQTTCom::pubish(int sensor1, int sensor2, int water) {
  String json;

  DynamicJsonDocument doc(1024);
  doc["device"] = "ESP32";
  doc["sensor1"] = String(sensor1);
  doc["sensor2"] = String(sensor2);
  doc["water"] = String(water);
  serializeJson(doc, json);

  client.loop();
  client.publish("iot/water", json.c_str());
}