#include <Arduino.h>
#include <cstdint> // Necesario para el manejo de variables de tamaño fijo
#include <WiFi.h>  // Librería necesaria para utilizar funciones Wi-Fi
#include <PubSubClient.h>
#include <config.h>
#include <MqttManager.h>

WiFiClient clienteTCP_IP; 
// Objeto de la clase WiFiClient que representa una conexión TCP/IP (socket).

PubSubClient mqttClient(clienteTCP_IP); 
// Objeto que implementa el protocolo MQTT. Requiere un cliente TCP/IP para la comunicación.

// Indica al ESP32 los topics a los que se suscribe
void SuscribeMqtt()
{
    mqttClient.subscribe("sonda_HT"); // Topic al que se suscribe el cliente MQTT
}

// Variable privada accesible solo desde este archivo
static String Datos_Peticion = ""; 

// Getter para acceder al dato desde otros módulos
String getDatosPeticion() { return Datos_Peticion; }

// Callback que se ejecuta al recibir un mensaje MQTT
void OnMqttReceived(char *topic, byte *payload, unsigned int length)
{
    Serial.print("Received on ");
    Serial.print(topic);
    Serial.print(": ");

    Datos_Peticion = ""; // Limpia el buffer

    // Conversión de bytes a String
    for (size_t i = 0; i < length; i++)
    {
        Datos_Peticion.concat((char)payload[i]);
    }

    Serial.print(Datos_Peticion);
    Serial.println();
}

// Inicialización del cliente MQTT
void InitMqtt()
{
    mqttClient.setServer(MQTT_BROKER_ADDRESS, MQTT_PORT);
    mqttClient.setCallback(OnMqttReceived);
    SuscribeMqtt();
}

// Muestra información y gestiona la conexión al broker
void ConnectMqtt()
{
    Serial.println("");
    Serial.print("ESP32 IP: ");
    Serial.println(WiFi.localIP());

    Serial.print("Conectando a broker: ");
    Serial.print(MQTT_BROKER_ADDRESS);
    Serial.print(":");
    Serial.println(MQTT_PORT);

    // Reintenta hasta conectar
    while (!mqttClient.connected())
    {
        if (mqttClient.connect(MQTT_CLIENT_NAME))
        {
            Serial.println("¡Conectado al broker!");
            SuscribeMqtt(); // Re-suscripción automática tras reconexión
        }
        else
        {
            Serial.print("Fallo rc=");
            Serial.print(mqttClient.state());
            Serial.print(" estado WiFi=");
            Serial.println(WiFi.status());

            delay(5000); // Espera antes de reintentar
        }
    }
}

// Mantiene la conexión MQTT (llamar en loop)
void HandleMqtt()
{
    if (!mqttClient.connected())
    {
        ConnectMqtt();
    }

    mqttClient.loop(); // Procesa mensajes entrantes y mantiene la conexión activa
}

