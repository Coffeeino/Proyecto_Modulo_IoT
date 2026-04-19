#include <Arduino.h>
#include <WebServer.h>
#include <misFuncionesWebServer.h>

static float temperatura = 0.0; //Privada solo accesible desde este archivo

void setTemperatura(float t) { temperatura = t; }
float getTemperatura() { return temperatura; }

// Función que se ejecuta en URI '/' (La “ruta” dentro de una web o servidor)
// “Cuando alguien entre a la URI /, ejecuta handleRoot()”
// Se ejecuta cuando el navegador pide: http://IP_DEL_ESP32/
void handleRoot()
{
    String mensaje = "Temperatura: " + String(temperatura);
    servidor.send(200, "text/plain", mensaje);
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
