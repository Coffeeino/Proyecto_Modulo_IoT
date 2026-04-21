// En "config.h" centralizamos la configuración del proyecto para que los valores no esten esparcidos por distintas partes del proyecto.

#pragma once    // Evita definiciones duplicadas por diferentes archivos que hagan "#include" de el mismo archivo.h.
                // "#pragma" le dice al compilador:"Incluye este archivo una sola vez sin importar cuantas veces se haga #include de el"

// Datos red Wifi
// Cambiar valores aquí para acceder a puntos de acceso Wifi.
#define WIFI_SSID "klicon_voip"           // Nombre del punto de acceso wifi
#define WIFI_PASSWORD "Climacontrol1"  // Contraseña del punto de acceso wifi

// Datos comunicación MQTT
// Cambiar valores aquí para estableces la conexión MQTT con el servidor en el que se aloja el broker.
#define MQTT_PORT 1883                      // Puerto en el que se establece la comunicación.
#define MQTT_CLIENT_NAME "Cliente_ESP32"    // ID del ESP32 como cliente del broker.
#define MQTT_BROKER_ADRESS "172.26.0.248"    // IP del servidor en el que se aloja el broker.
