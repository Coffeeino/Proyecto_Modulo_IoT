// Más información en: https://www.luisllamas.es/como-emplear-el-esp8266-como-servidor/

// Necesarios para crear servidor web
#include <Arduino.h>
#include <WiFi.h>      //Librería para importar funciones Wifi
#include <WebServer.h> //librería para importar funciones servidor web

#include <wifiManager.h>
#include <misFuncionesWebServer.h>
#include <config.h> // Ir a include/config.h para cambiar parámetros de conexión de punto de acceso

#include <SPIFFS.h>
#include <misFuncionesMqtt.h>  

WebServer servidor(80);

void setup()
{
  // put your setup code here, to run once:

  Serial.begin(9600);
  SPIFFS.begin();

  ConnectWifi_STA();
  InitMqtt();
  InitServer();
  
}

void loop()
{
  // put your main code here, to run repeatedly:
  HandleMqtt();
  servidor.handleClient();
  
}
