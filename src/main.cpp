// Más información en: https://www.luisllamas.es/como-emplear-el-esp8266-como-servidor/
#include <Arduino.h>
#include <WiFi.h>      //Librería para importar funciones Wifi
#include <WebServer.h> //librería para importar funciones servidor web

#include <wifiManager.h>
#include <webserver.h>
#include <config.h> // Ir a include/config.h para cambiar parámetros de conexión de punto de acceso

WebServer servidor(80);

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  ConnectWifi_STA();
  InitServer();
}

void loop()
{
  // put your main code here, to run repeatedly:
  servidor.handleClient();
}