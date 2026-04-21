// El archivo "globals.cpp" contiene la definición de objetos y variables que serán usados en más de un ".cpp".
// Si, por ejemplo, un objeto solo se usa en main.cpp, se define directamente en ese archivo.

// Aunque globals.cpp no utilice nada de globals.h, lo incluimos como buena práctica para la detección de errores.
#include <globals.h>
#include <WebServer.h>

WebServer servidor(80); // Creación del objeto "servidor" de la clase "WebServer". Escucha en el puerto 80 (puerto estándar HTTP).
float temperatura = 0.0; // Definición de la variable "temperatura" de tipo float.
