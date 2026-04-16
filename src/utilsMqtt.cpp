// contiene funciones que genéricas para comunicación en MQTT.
// Está pensado para contener código que podéis reusar entre proyectos con poca o ninguna modificación.

#include <misFuncionesMqtt.h>
const uint16_t MQTT_PORT = 1883;

void InitMqtt()
{
    mqttClient.setServer(MQTT_BROKER_ADRESS, MQTT_PORT);
    SuscribeMqtt();
    mqttClient.setCallback(OnMqttReceived);
}

void ConnectMqtt()
{
    while (!mqttClient.connected())
    {
        Serial.print("Iniciando conexión MQTT...");
        if (mqttClient.connect(MQTT_CLIENT_NAME))
        {
            SuscribeMqtt();
        }
        else
        {
            Serial.print("Conexión MQTT fallida, rc=");
            Serial.print(mqttClient.state());
            Serial.println("Reconexión en 5 segundos...");

            delay(5000);
        }
    }
}

void HandleMqtt()
{
    if (!mqttClient.connected())
    {
        ConnectMqtt();
    }
    mqttClient.loop();
}