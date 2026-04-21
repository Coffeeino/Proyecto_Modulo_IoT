// El proposito de globals.h es heredar los objetos declarados en globals.cpp y de esta manera incluirlos en cualquier archivo que quiera usar estas variables, funcionaría si eliminamos globals.h e incluimos "extern" en cada archivo que necesite usar las variables globales pero sería reptitivo y complicaría en mantenimiento del programa.

#pragma once // Avisa al compilador que aunque <globals.h> sea llamado en mas de un achivo, solo lo defina una vez.
#include <WebServer.h>

extern WebServer servidor; // Indica que el objeto "servidor" del tipo "WebServer" ya esta declarado en otro lado.(globals.cpp)
extern float temperatura;  // Indica que el objeto "temperatura" del tipo "float" ya esta declarado en otro lado.(globals.cpp)