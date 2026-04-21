#pragma once    // Aviso al compilador que aunque misFuncionesWebServer esten declaradas en diferentes archivos, solo se declare una vez.
#include <WebServer.h>  // Libreria "WebServer.h"

extern WebServer servidor;  // Avisa que el objeto servidor ya existe y esta declarado en otro lado.

void InitServer();  // Como esta función se va a usar en otro archivo se debe de declarar en misFuncionesWebServer.h
