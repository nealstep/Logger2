#include <Arduino.h>

#if defined(ESP8266)
#include <ESP8266WiFi.h>
#else
#error "Not supported"
#endif  // ESP8266
#include <PubSubClient.h>

#include "Logger2.h"

#define ID_SIZE 16

// passed constants
static const char *ssid = MY_SSID;
static const char *passwd = MY_PASSWD;
static const uint32_t baud = MY_BAUD;
static const char *mqttHost = MY_MQTT_HOST;
static const uint16_t mqttPort = MY_MQTT_PORT;
static const char *mqttLogTopic = MY_MQTT_LOG_TOPIC;

// global constants
static const uint16_t delayMedium = 250;
static const uint16_t delayLong = 1000;
static const uint32_t interval = 30000;

// major classes
WiFiClient espWiFiClient;
PubSubClient mqttClient(espWiFiClient);
Logger2 logger;

// global variables
uint32_t currentMillis;
uint32_t previousMillis = 0;
uint16_t interval_count = 0;
bool ledStatus = false;
char mqttID[ID_SIZE];

void wifi_setup(void) {
    IPAddress localIP;

    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, passwd);

    logger.log(logger.DEBUG, "Connecting to WiFi");
    while (WiFi.status() != WL_CONNECTED) {
        logger.log(logger.DEBUG, "Waiting to connect to WiFi");
        delay(delayMedium);
    }
    localIP = WiFi.localIP();
    logger.info("WiFi connected local IP", localIP[0], localIP[1], localIP[2],
                localIP[3]);

    WiFi.setAutoReconnect(true);
    WiFi.persistent(true);
}

void mqttCheck() {
    while (!mqttClient.connected()) {
        logger.debug("Connecting to MQTT");
        if (mqttClient.connect(mqttID)) {
            logger.setMQTT(mqttClient, mqttLogTopic);
            logger.info("MQTT Connected");
        } else {
            logger.error("MQTT connect failed rc", mqttClient.state());
            delay(delayLong);
        }
    }
}

void setup() {
    Serial.begin(baud);
    logger.setPrint(Serial);
    logger.setLevel(logger.DEBUG);
    logger.info("Starting");
    pinMode(LED_BUILTIN, OUTPUT);
    mqttClient.setServer(mqttHost, mqttPort);
    wifi_setup();
    strncpy(mqttID, WiFi.hostname().c_str(), ID_SIZE - 2);
    mqttID[ID_SIZE - 1] = '\0';
    mqttCheck();
    logger.debug("Setup done");
}

void blink(void) {
    logger.debug("Blink");
    ledStatus = !ledStatus;
    digitalWrite(LED_BUILTIN, ledStatus);
}

void loop() {
    currentMillis = millis();
    mqttClient.loop();
    if (currentMillis - previousMillis >= interval) {
        logger.debug("Loop check");
        blink();
        switch (WiFi.status()) {
            case WL_NO_SSID_AVAIL:
                logger.log(logger.ERROR, "Configured SSID cannot be reached");
                break;
            case WL_CONNECTED:
                logger.log(logger.INFO, "Connection successfully established");
                break;
            case WL_CONNECT_FAILED:
                logger.log(logger.WARNING, "Connection failed");
                break;
            default:
                break;
        }
        logger.value("RSSI", WiFi.RSSI());
        interval_count++;
        if (interval_count == 10) {
            logger.setLevel(logger.INFO);
        }
        mqttCheck();
        previousMillis = currentMillis;
    }
}
