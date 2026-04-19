#pragma once
#include <WebServer.h>

extern WebServer servidor;

void InitServer();
void setTemperatura(float t);   //Setter
float getTemperatura();         //Getter
