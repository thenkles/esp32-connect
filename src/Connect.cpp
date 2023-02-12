#include "Connect.h"
#include <functional>
#include "ArduinoJson.h"

using namespace std;

Connect::Connect()
{
    _webServer = new AsyncWebServer(80);
    _webSocket = new AsyncWebSocket("/config");
}

void Connect::begin(FS *fileSystem)
{
    this->_webSocket->onEvent(bind(&Connect::onWebSocketEvent, this, placeholders::_1, placeholders::_2, placeholders::_3, placeholders::_4, placeholders::_5, placeholders::_6));
    this->_webServer->addHandler(_webSocket);

    this->_webServer->begin();
    this->_settings = new Settings(fileSystem);
}

void Connect::loop()
{
    this->_webSocket->cleanupClients();
}

void Connect::addStandardWiFiSettings()
{
}

void Connect::onWebSocketEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len)
{
    switch (type)
    {
    case WS_EVT_CONNECT:
        Serial.printf("WebSocket client #%u connected from %s\n", client->id(), client->remoteIP().toString().c_str());
        break;
    case WS_EVT_DISCONNECT:
        Serial.printf("WebSocket client #%u disconnected\n", client->id());
        break;
    case WS_EVT_DATA:
        this->onWebSocketMessage(arg, data, len);
        break;
    case WS_EVT_PONG:
    case WS_EVT_ERROR:
        break;
    }
}

void Connect::onWebSocketMessage(void *arg, uint8_t *data, size_t len)
{
    AwsFrameInfo *info = (AwsFrameInfo *)arg;
    if (info->final && info->index == 0 && info->len == len && info->opcode == WS_TEXT)
    {
        data[len] = 0;
        Serial.println("Message:");
        Serial.println((const char *)data);

        DynamicJsonDocument doc(1024);
        deserializeJson(doc, data);

        const char *command = doc["command"];
        JsonObject params = doc["params"].as<JsonObject>();

        if (strcmp(command, "scan-wifi"))
        {
            this->onNetworkScanRequested();
        }
        // else if (strcmp(command, "get-config-pages"))
        // {
        //     this->onConfigurationPagesRequested(params);
        // }
        // else if (strcmp(command, "get-config-settings"))
        // {
        //     this->onConfigurationSettingsRequested(params);
        // }
    }
}

void Connect::onNetworkScanRequested()
{
    Serial.println("Network scan requested.");
}

// void Connect::onConfigurationPagesRequested(JsonObject params)
// {
//     Serial.println("Configuration pages requested.")
// }

// void Connect::onConfigurationSettingsRequested(JsonObject params)
// {
// }