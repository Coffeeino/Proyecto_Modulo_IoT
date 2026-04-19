// contiene funciones que genéricas para comunicación en MQTT.
// Está pensado para contener código que podéis reusar entre proyectos con poca o ninguna modificación.

#include <misFuncionesMqtt.h>
#include <config.h>


void InitMqtt()
{
    mqttClient.setServer(MQTT_BROKER_ADRESS, MQTT_PORT);
    SuscribeMqtt(); 
    mqttClient.setCallback(OnMqttReceived);
}

void ConnectMqtt()
{
    Serial.println("");
    Serial.print("ESP32 IP: ");
    Serial.println(WiFi.localIP());
    Serial.print("Conectando a broker: ");
    Serial.print(MQTT_BROKER_ADRESS);
    Serial.print(":");
    Serial.println(MQTT_PORT);

    while (!mqttClient.connected())
    {
        if (mqttClient.connect(MQTT_CLIENT_NAME))
        {
            Serial.println("¡Conectado al broker!");
            SuscribeMqtt();
        }
        else
        {
            Serial.print("Fallo rc=");
            Serial.print(mqttClient.state());
            Serial.print(" estado WiFi=");
            Serial.println(WiFi.status());
            delay(5000);<z
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