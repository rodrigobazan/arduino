#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <Hash.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>

#include "config.h"
#include "ESP8266_Utils.hpp"
#include "server.hpp"
#include "sensor.hpp"

unsigned long previousMillis = 0; 

const long interval = 10000;  

void setup() {
  Serial.begin(115200);
  initSensor();

  ConnectWiFi_STA();
  initServer();

}

void loop() {
  unsigned long currentMillis = millis();
  if(currentMillis - previousMillis >= interval){
    previousMillis = currentMillis;
    float newT = leerTemperatura();
    if(isnan(newT)){
      Serial.println("Error al leer temperatura");
    }else{
      t = newT;
      Serial.println(t);
    }
    float newH = leerHumedad();
    if (isnan(newH)) {
      Serial.println("Error al leer humedad");
    }
    else {
      h = newH;
      Serial.println(h);
    }
  }

}
