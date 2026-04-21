// En "config.h" centralizamos la configuración del proyecto para que los valores no estén esparcidos por distintas partes.
#pragma once // Evita definiciones duplicadas por diferentes archivos que hagan "#include" del mismo archivo.h.
             // "#pragma" le dice al compilador: "Incluye este archivo una sola vez sin importar cuántas veces se haga #include de él"

// Datos red Wi-Fi
// Cambiar valores aquí para acceder a puntos de acceso Wi-Fi.
#define WIFI_SSID "klicon_voip"       // Nombre del punto de acceso Wi-Fi
#define WIFI_PASSWORD "Climacontrol1" // Contraseña del punto de acceso Wi-Fi

// Datos comunicación MQTT
// Cambiar valores aquí para establecer la conexión MQTT con el servidor en el que se aloja el broker.
#define MQTT_PORT 1883                     // Puerto en el que se establece la comunicación.
#define MQTT_CLIENT_NAME "Cliente_ESP32"   // ID del ESP32 como cliente del broker.
#define MQTT_BROKER_ADDRESS "172.26.0.248" // IP del servidor en el que se aloja el broker.
