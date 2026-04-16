// Más información en: https://www.luisllamas.es/como-conectar-un-esp8266-a-una-red-wifi-modo-sta/

#include <Arduino.h>
#include <WiFi.h>

#include <config.h>
#include <wifiManager.h>

void ConnectWifi_STA()
{
    Serial.println("");
    WiFi.mode(WIFI_STA);
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);   // Conexión del ESP32 a punto de acceso WIFI.
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(100);
        Serial.print('.');
    }

    Serial.println("");
    Serial.print("Iniciando STA:\t");
    Serial.println(WIFI_SSID);
    Serial.print("Dirección IP:\t");
    Serial.println(WiFi.localIP());
}
