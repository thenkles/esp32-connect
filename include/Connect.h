#pragma once

#include <Arduino.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include "settings.h"
#include "FS.h"

using namespace fs;

class Connect
{
public:
    Connect();
    void begin(FS *fileSystem);
    void loop();
    void addStandardWiFiSettings();
private:
    AsyncWebServer *_webServer;
    AsyncWebSocket *_webSocket;
    Settings *_settings;
    void onWebSocketEvent(AsyncWebSocket * server, AsyncWebSocketClient * client, AwsEventType type, void * arg, uint8_t *data, size_t len);
    void onWebSocketMessage(void *arg, uint8_t *data, size_t len);
    void onNetworkScanRequested();
    // void onConfigurationPagesRequested(JsonObject params);
    // void onConfigurationSettingsRequested(JsonObject params);
};