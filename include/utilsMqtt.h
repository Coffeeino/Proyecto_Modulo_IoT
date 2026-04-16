#pragma once

#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>

extern const char* MQTT_BROKER_ADRESS;
extern const uint16_t MQTT_PORT;
extern const char* MQTT_CLIENT_NAME;
extern const uint16_t MQTT_PORT;

extern WiFiClient clienteTCP_IP;
extern PubSubClient mqttClient;

void InitMqtt();
void ConnectMqtt();
void HandleMqtt();
void SuscribeMqtt();
void OnMqttReceived(char* topic, byte* payload, unsigned int length);