#include <Arduino.h>
#include <WiFi.h>
#include "Connect.h"
#include "SPIFFS.h"

const char *ssid = "Imperium Ojca Dyrektora";
const char *password = "Zawsze0gladamTelewizjeTrwam!";

Connect *_connect;

void setup()
{
  Serial.begin(115200);

  Serial.print("Connecting to WiFi...");

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.print(".");
  }

  Serial.println();

  // Print ESP Local IP Address
  Serial.println(WiFi.localIP());

  SPIFFS.begin();
  _connect = new Connect();
  _connect->begin(&SPIFFS);
}

void loop()
{
  _connect->loop();
}