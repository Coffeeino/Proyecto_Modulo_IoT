#include <Arduino.h>
#include <WebServer.h>

extern WebServer servidor;

// Función que se ejecuta en URI '/' (La “ruta” dentro de una web o servidor)
// “Cuando alguien entre a la URI /, ejecuta handleRoot()”
// Se ejecuta cuando el navegador pide: http://IP_DEL_ESP32/
void handleRoot()
{
    servidor.send(200, "text/plain", "Hola mundo!");
}

// Funcion que se ejecutara en URI desconocida
// Ejemplo, si tengo servidor.on("/", handleRoot); y alguien escribe http://IP_DEL_ESP32/led
// como /led no está definido se ejecuta handleNotFound()
void handleNotFound()
{
    servidor.send(404, "text/plain", "Not found");
}

void InitServer()
{
    // Ruteo para '/'
    servidor.on("/", handleRoot);

    // Ruteo para '/inline' usando funcion lambda
    servidor.on("/inline", []()
                { servidor.send(200, "text/plain", "Esto tambien funciona"); });

    // Ruteo para URI desconocida
    servidor.onNotFound(handleNotFound);

    // INICIAR SERVIDOR
    servidor.begin();
    Serial.println("¡Servidor web iniciado!");
};
