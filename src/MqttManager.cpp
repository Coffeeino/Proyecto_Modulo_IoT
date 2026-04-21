#include <Arduino.h>
#include <cstdint> // Necesario para el manejo de variables con tipo de tamaño fijo
#include <WiFi.h>  // Librería necesaria para utilizar funciones Wifi
#include <PubSubClient.h>
#include <config.h>
#include <MqttManager.h>

WiFiClient clienteTCP_IP;               // Crear objeto de la clase WifiCliente que representa una conexión TCP/IP mediante wifi. Basicamente es un socket, un canal de comunicación entre dos dispositivos.  .
PubSubClient mqttClient(clienteTCP_IP); // Crea objeto de la clase PubSubClient que implementa el protocolo MQTT con funciones necesarias para conexión, suscripción, publicacición... Necesita que le pasamos el canal de comunicación, el socket.

void SuscribeMqtt() // Indica al ESP32 los topic que queremos escuchar
{
    mqttClient.subscribe("sonda_HT"); // Topic al que se suscribe el cliente MQTT
}

//Declaración de variable privada para que solo MqttManager pueda tener acceso a modificar el valor del dato recibido por Mqtt. Y evitar que pueda ser cambiado desde otro punto del programa causando errores en el programa.
static String Datos_Peticion = ""; // Declaración de String vacío para alojar el dato solicitado.
String getDatosPeticion() { return Datos_Peticion; } // construcción del getter necesario para que otros archivos puedan acceder a la lectura del valor. Lo usará WebSeverManager.cpp para obtener el valor y mostrarlo en el servidor.

void OnMqttReceived(char *topic, byte *payload, unsigned int length) // Función Callback deMQTT que se ejecuta cada vez que llega un mensaje del broker, su ejecución depende de que lo indique otra función.
{
    Serial.print("Received on ");
    Serial.print(topic);    // Imprime el topic
    Serial.print(": ");

    Datos_Peticion = "";    // Limpia el buffer
    for (size_t i = 0; i < length; i++)     // Como la información llega en bytes, se debe recorrer el array de bytes.
    {
        Datos_Peticion.concat((char)payload[i]);    // En cada vuelta se concatena los bytes recibidos y se leen como string
    }
    Serial.print(Datos_Peticion);   // Muestra es String
    Serial.println();
}

// Función para la inicialización del cliente MQTT, prepara todo antes de conectarse al broker.
void InitMqtt()
{
    mqttClient.setServer(MQTT_BROKER_ADRESS, MQTT_PORT);    // Le dice al ESP32donde esta el broker y el puerto. estos datos vienen de config.h
    SuscribeMqtt(); // Llama a la función anterior creada por nosotros para la suscripción en los topics.
    mqttClient.setCallback(OnMqttReceived);     //  Registro del callback OnMqttReceived.
}

void ConnectMqtt()  // Función para el diagnóstico antes de conectar:
{
    Serial.println("");
    Serial.print("ESP32 IP: ");
    Serial.println(WiFi.localIP());
    Serial.print("Conectando a broker: ");
    Serial.print(MQTT_BROKER_ADRESS);
    Serial.print(":");
    Serial.println(MQTT_PORT);

    // Bucle que se repite mientras no esté conectado al broker. No sale de el hasta conseguir conexión.
    while (!mqttClient.connected()) 
    {   
        // Si la conexión tiene exito.
        if (mqttClient.connect(MQTT_CLIENT_NAME))   // Intenta conectarse al broker con el nombre del cliente que viene de config.h
        {
            Serial.println("¡Conectado al broker!");
            SuscribeMqtt(); // Se suscribe aqui tambien a los topics en caso de que el cliente se caiga y se vuelva a coenctar se vuelva a suscribir automaticamente.
        }
        else    // Aviso cíclico de el intento fallido de conexión.
        {
            Serial.print("Fallo rc=");
            Serial.print(mqttClient.state());   // Código de error Mqtt.
            Serial.print(" estado WiFi=");
            Serial.println(WiFi.status());
            delay(5000);    // Espera de 5s antes de reintentar conexión.
        }
    }
}

void HandleMqtt()   // Mantiene la conexión MQTT, se ejecuta en cada iteración del .loop()
{
    if (!mqttClient.connected())    // Comprueba en cada ciclo si la conexión con el broker sigue activa. Si no esta activa, se llama 
    {
        ConnectMqtt();  // para la reconexión.
    }
    mqttClient.loop();  // le da tiempo de CPU al cliente MQTT para revisar si hay mensajes nuevos, y si hay alguno que ejecute el callback OnMqttReceived() y mantener viva la conexión.
}