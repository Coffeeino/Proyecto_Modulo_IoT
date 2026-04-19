#include <Arduino.h>
#include <cstdint> // Necesario para el manejo de variables con tipo de tamaño fijo
#include <WiFi.h>  // Librería necesaria para utilizar funciones Wifi
#include <PubSubClient.h>
#include <config.h>


WiFiClient clienteTCP_IP;               // Crear objeto de la clase clienteTCP/IP que tendrá las funciones necesarias para abrir sockets necesarios para la conxión a servidores.
PubSubClient mqttClient(clienteTCP_IP); // Crea el cliente MQTT listo para conetar al broker

void SuscribeMqtt() // Indica al ESP32 los topic que queremos escuchar
{
    mqttClient.subscribe("sonda_HT"); // Topic al que se suscribe el cliente MQTT
}

static String Datos_Peticion = ""; // Declaración de String vacío para alojar el dato solicitado.
String getDatosPeticion() { return Datos_Peticion; }

void OnMqttReceived(char *topic, byte *payload, unsigned int length)
{
    Serial.print("Received on ");
    Serial.print(topic);
    Serial.print(": ");

    Datos_Peticion = "";
    for (size_t i = 0; i < length; i++)
    {
        Datos_Peticion.concat((char)payload[i]);
    }
    Serial.print(Datos_Peticion);
    Serial.println();
}
