#pragma once 
#include <WiFi.h>
#include <PubSubClient.h>

extern WiFiClient clienteTCP_IP;
extern PubSubClient mqttClient;

extern const char* MQTT_BROKER_ADRESS;
extern const char* MQTT_CLIENT_NAME;
extern const uint16_t MQTT_PORT;

extern String Datos_Peticion;

void InitMqtt();
void ConnectMqtt();
void HandleMqtt();

void SuscribeMqtt();
void OnMqttReceived(char* topic, byte* payload, unsigned int length);
