#include <Arduino.h>
#include <WebServer.h>
#include <WebServerManager.h>
#include <globals.h>
#include <MqttManager.h>
#include <LittleFS.h>

// Función que se ejecuta en URI '/' (La “ruta” dentro de una web o servidor)
// “Cuando alguien entre a la URI /, ejecuta handleRoot()”
// Se ejecuta cuando el navegador pide: http://IP_DEL_ESP32/
void handleRoot() // Servidor ESP32 recibe una petición y devuelve una respuesta.
{

    // String mensaje = "<html><head>"
    //                 "<meta http-equiv='refresh' content='5'>"
    //                 "</head><body>"
    //                 "<h1>Temperatura: " + getDatosPeticion() + "</h1>"
    //                 "</body></html>";
    // servidor.send(200, "text/html", mensaje);

    File archivo = LittleFS.open("/index.html", "r");
    servidor.streamFile(archivo, "text/html");
    archivo.close();
}
void handleTemperatura()
{
    servidor.send(200, "text/plain", getDatosPeticion());
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
    servidor.on("/", handleRoot); // le dice al servidor que cuando alguien haga una petición a "/" ejecuta "handleRoot".
    servidor.on("/temperatura", handleTemperatura);
    // Ruteo para URI desconocida
    servidor.onNotFound(handleNotFound); // Le dice al servidor que utilice la función "handleNotFound() en caso de que se introduzca una dirección desconocida.

    // INICIAR SERVIDOR
    servidor.begin();
    Serial.println("¡Servidor web iniciado!");
};
