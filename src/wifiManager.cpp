// Más información en: https://www.luisllamas.es/como-conectar-un-esp8266-a-una-red-wifi-modo-sta/

#include <Arduino.h>
#include <WiFi.h>

#include <config.h> // Le decimos al compilador que valores de "config.h" serán utilizados en este archivo.
#include <WifiManager.h>   // incluimos el archivo .h para asegurar la detección de errores, por ejemplo, aqui declaramos que ConnectWifi_STA devuelve void, y si en .h ponemos int la consola notificará el error.


void ConnectWifi_STA()
{
    Serial.println("");
    WiFi.mode(WIFI_STA);    // Configura el ESP32 en modo estación, es decir, cliente que se conecta a un ruter.
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);   // Conexión del ESP32 a punto de acceso WIFI.
    
    // Espera en bucle hata que se logre la conexión, cada 100ms se imprime un . a modo de indicación que esta intentando conectarse.
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(100);
        Serial.print('.');
    }

    // Imprime los datos de la red a la que se conectó el esp32.
    Serial.println("");
    Serial.print("Iniciando STA:\t");
    Serial.println(WIFI_SSID);
    Serial.print("Dirección IP:\t");
    Serial.println(WiFi.localIP());
}
