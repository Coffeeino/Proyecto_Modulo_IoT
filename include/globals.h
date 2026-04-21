// globals.h hereda los objetos declarados en globals.cpp y de esta manera podemos incluirlos en cualquier archivo que quiera usar estas variables.
// Funcionaría si eliminamos globals.h e incluimos "extern" en cada archivo que necesite usar las variables globales, pero sería repetitivo
// y complicaría el mantenimiento del programa.

#pragma once // Indica al compilador que, aunque <globals.h> sea llamado en más de un archivo, solo lo defina una vez.
#include <WebServer.h>

extern WebServer servidor; // Indica que el objeto "servidor" del tipo "WebServer" ya está declarado en otro lado (globals.cpp)
extern float temperatura;  // Indica que el objeto "temperatura" del tipo "float" ya está declarado en otro lado (globals.cpp)
