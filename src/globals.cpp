// El archivo "globals.cpp" incluye la declaración de objetos y variables que serán usados en más de un ".cpp" en caso de que por ejemplo un objeto solo se use en main.cpp solo se declara en el main.cpp y listo.
// Aunque globals.cpp no utilice nada de globals.h se lo cargamos ya que es una buena práctica para detección de errores, 
#include <globals.h>
#include <WebServer.h>

WebServer servidor(80); // Creación de mi objeto "servidor" de la clase "WebServer". Escucha el puerto "80"(Puerto standar HTTP).
float temperatura = 0.0; // Declaración de la variable temperatura del tipo float.