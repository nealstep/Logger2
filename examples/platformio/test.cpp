#include <Arduino.h>

#if defined(ESP8266)
#include <ESP8266WiFi.h>
#else
#error "Not supported"
#endif  // ESP8266
#include <PubSubClient.h>

#include "Logger2.h"

static const char *ssid = MY_SSID;
static const char *passwd = MY_PASSWD;
static const uint32_t baud = MY_BAUD;

static uint16_t delayMedium = 250;
static uint16_t delayLong = 1000;

Logger2 logger;

uint32_t currentMillis;
uint32_t previousMillis = 0;
uint32_t interval = 30000;
uint16_t interval_count = 0;
bool ledStatus = false;

void wifi_setup(void) {
    IPAddress localIP;

    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, passwd);

    logger.log(logger.INFO, "Connecting to WiFi ..");
    while (WiFi.status() != WL_CONNECTED) {
        logger.log(logger.DEBUG, "Waiting to connect");
        delay(delayMedium);
    }
    localIP = WiFi.localIP();
    logger.info("Local IP", localIP[0], localIP[1], localIP[2], localIP[3]);
    WiFi.setAutoReconnect(true);
    WiFi.persistent(true);
}

void setup() {
    Serial.begin(baud);
    logger.setPrint(Serial);
    logger.setLevel(logger.DEBUG);
    logger.info("Strarting");
    pinMode(LED_BUILTIN, OUTPUT);
    wifi_setup();
}

void blink(void) {
    logger.debug("Blink");
    ledStatus = !ledStatus;
    digitalWrite(LED_BUILTIN, ledStatus);
}

void loop() {
    currentMillis = millis();
    if (currentMillis - previousMillis >= interval) {
        blink();
        switch (WiFi.status()) {
            case WL_NO_SSID_AVAIL:
                logger.log(logger.ERROR,
                           "Configured SSID cannot be reached");
                break;
            case WL_CONNECTED:
                logger.log(logger.INFO,
                           "Connection successfully established");
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
        previousMillis = currentMillis;
    }
}
