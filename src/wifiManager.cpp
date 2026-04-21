#include <Arduino.h>
#include <WiFi.h>

#include <config.h>      // Indica al compilador que los valores de "config.h" se usan en este archivo
#include <WifiManager.h> // Incluye el header para detección de errores entre declaración y definición

void ConnectWifi_STA()
{
    Serial.println("");

    WiFi.mode(WIFI_STA);                  // Configura el ESP32 en modo estación (cliente Wi-Fi)
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD); // Inicia la conexión al punto de acceso Wi-Fi

    // Espera hasta establecer conexión
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(100);
        Serial.print('.');
    }

    // Información de conexión
    Serial.println("");
    Serial.print("Iniciando STA:\t");
    Serial.println(WIFI_SSID);

    Serial.print("Dirección IP:\t");
    Serial.println(WiFi.localIP());
}

