// Avisa al compilador que, aunque WebServerManager.h esté incluido en diferentes archivos, solo se procese una vez.
#pragma once

#include <WebServer.h> // Librería "WebServer.h"

extern WebServer servidor; // Indica que el objeto "servidor" ya existe y está declarado en otro archivo.

void InitServer(); // Como esta función se va a usar en otro archivo, debe declararse aquí, en WebServerManager.h

