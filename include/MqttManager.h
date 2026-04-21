// Avisa al compilador que, aunque MqttManager.h esté declarado en diferentes archivos, solo se declare una vez.
#pragma once

// Funciones de WebServerManager.cpp que serán usadas por otros archivos, las declaramos aquí en WebServerManager.h,
// y gracias a pragma evitamos fallos críticos de compilación como múltiples declaraciones.
void InitMqtt();
void HandleMqtt();
String getDatosPeticion();
