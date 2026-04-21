// Para más información sobre los recursos, ver el árbol del proyecto en mi repositorio:
// https://github.com/Coffeeino/Proyecto_Modulo_IoT.git

// Ir a include/config.h para cambiar parámetros de conexión al punto de acceso y al broker MQTT.
#include <config.h>

// Librería del framework de Arduino. Necesaria para implementar funciones de comunicación Serial entre el ESP32 y el monitor serie.
#include <Arduino.h>

// Librería de funciones Wi-Fi.
#include <WiFi.h>

// Librerías para el servidor web
#include <WebServer.h> // Proporciona funcionalidades para crear un servidor web
#include <LittleFS.h>  // Permite usar la memoria flash del ESP32 para alojar el archivo HTML del servidor

// Headers
#include <WifiManager.h>      // Declaración de funciones de WifiManager.cpp
#include <WebServerManager.h> // Declaración de funciones de WebServerManager.cpp
#include <MqttManager.h>      // Declaración de funciones de MqttManager.cpp

void setup()
{
  // Código que se ejecuta una sola vez al inicio del programa.

  // Inicializa la comunicación serie (9600 baudios).
  Serial.begin(9600);

  if (!LittleFS.begin())
  {
    Serial.println("Error montando LittleFS");
  }
  else
  {
    Serial.println("LittleFS montado correctamente");
  }

  ConnectWifi_STA(); // Inicializa la conexión Wi-Fi
  InitMqtt();        // Inicializa la conexión MQTT
  InitServer();      // Inicializa el servidor web en el ESP32
}

void loop()
{
  // Código que se ejecuta cíclicamente.
  HandleMqtt();            // Gestiona la conexión MQTT
  servidor.handleClient(); // Atiende las peticiones de clientes al servidor web
}
