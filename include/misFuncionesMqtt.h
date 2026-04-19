#pragma once 
#include <WiFi.h>
#include <PubSubClient.h>

extern WiFiClient clienteTCP_IP;
extern PubSubClient mqttClient;

String getDatosPeticion();

void InitMqtt();
void ConnectMqtt();
void HandleMqtt();

void SuscribeMqtt();
void OnMqttReceived(char* topic, byte* payload, unsigned int length);
