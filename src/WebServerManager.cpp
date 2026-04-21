#include <Arduino.h>
#include <WebServer.h>
#include <WebServerManager.h>
#include <globals.h>
#include <MqttManager.h>
#include <LittleFS.h>

// Handler para la URI "/"
// Se ejecuta cuando el navegador accede a: http://IP_DEL_ESP32/
void handleRoot()
{
    File archivo = LittleFS.open("/index.html", "r");
    servidor.streamFile(archivo, "text/html");
    archivo.close();
}

// Endpoint que devuelve la temperatura en texto plano
void handleTemperatura()
{
    servidor.send(200, "text/plain", getDatosPeticion());
}

// Handler para URIs no definidas
void handleNotFound()
{
    servidor.send(404, "text/plain", "Not found");
}

// Inicialización del servidor web
void InitServer()
{
    servidor.on("/", handleRoot);                 // Ruta principal
    servidor.on("/temperatura", handleTemperatura); // Endpoint de temperatura

    // Manejo de rutas no definidas
    servidor.onNotFound(handleNotFound);

    servidor.begin();
    Serial.println("¡Servidor web iniciado!");
}


