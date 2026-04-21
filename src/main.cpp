// Más información en: https://www.luisllamas.es/como-emplear-el-esp8266-como-servidor/

// Necesarios para crear servidor web
#include <Arduino.h>   // Librería del framework de Arduino. Necesaria para implementar funciones se comunicación Serial entre el ESP32 y el monitor serial.
#include <WiFi.h>      // Librería para importar funciones Wifi
#include <WebServer.h> // librería para importar funciones servidor web
#include <LittleFS.h>  //  librería que permite usar la memoria flash del ESP32  para poder alojar el "archivo.html" del servidor.

// Mis .h
#include <WifiManager.h>      // helpar para declarar las fucniones programadas en wifiManager.cpp
#include <WebServerManager.h> // helper para declarar las funciones de misFuncionesWebServer.cpp
#include <config.h>           // Ir a include/config.h para cambiar parámetros de conexión de punto de acceso.

#include <MqttManager.h>

void setup()
{
  // Código que solo se ejecuta 1 vez al inicio del programa.

  Serial.begin(9600); // Llamada a objeto "Serial" para que ejecute el método ".begin()" para abrir la comunicación,(9600 indica los baudios de la comunicación).
  if (!LittleFS.begin())
  { // ← el "true" formatea automáticamente si falla
    Serial.println("Error montando LittleFS");
  }
  else
  {
    Serial.println("LittleFS montado correctamente");
  }

  ConnectWifi_STA(); // Función creada en misFuncionesWifi.cpp para el arranque de la conexión Wifi.
  InitMqtt();
  InitServer(); // Función creada en misFuncionesWebServer.cpp para el arranque ser servidor esp32.
}

void loop()
{
  // Código que se ejecuta ciclicamente.
  HandleMqtt();
  servidor.handleClient(); // Función de librería WebServer.h, hace que el esp32 revise si hay algún cliente esperando una petición y la atiende.
}
