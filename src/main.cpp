// Más información en: https://www.luisllamas.es/como-emplear-el-esp8266-como-servidor/
#include <Arduino.h>
#include <WiFi.h> //Librería para importar funciones Wifi
#include <WebServer.h>  //librería para importar funciones servidor web

#include <config.h> // Ir a include/config.h para cambiar parámetros de conexión de punto de acceso

WebServer servidor(80);

// put function declarations here:
int myFunction(int, int);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  WiFi.mode(WIFI_AP_STA);

}

void loop() {
  // put your main code here, to run repeatedly:
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}