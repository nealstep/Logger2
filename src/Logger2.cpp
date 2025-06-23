#include "Logger2.h"

void Logger2::setPrint(Print &loggerPrint) {
    print = &loggerPrint;
    usePrint = true;
}

void Logger2::setMQTT(PubSubClient &pubSubClient, const char *logTopic) {
    client = &pubSubClient;
    topic = logTopic;
    useMQTT = true;
}

void Logger2::setLevel(LogLevel level) { logLevel = level; }

void Logger2::log(const char *msg) {
    if (usePrint) {
        print->println(msg);
    }
    if (useMQTT) {
        client->publish(topic, msg);
    }
}
void Logger2::log(LogLevel level, const char *msg) {
    if (level < logLevel) return;
    log(msg);
}
void Logger2::log(LogLevel level, const char *name, const char *value) {
    if (level < logLevel) return;
    char buffer[LOGGER_BUFFER_SIZE];
    char prefix = prefixes[static_cast<int>(level)];
    sprintf(buffer, "%c %s: %s", prefix, name, value);
    log(buffer);
}
void Logger2::log(LogLevel level, const char *name, uint64_t value,
                 uint8_t base) {
    if (level < logLevel) return;
    char bufferUInt[sizeof(uint64_t)*8+1];
    ultoa(value, bufferUInt, base);
    log(level, name, bufferUInt);
}
void Logger2::log(LogLevel level, const char *name, uint32_t value,
                 uint8_t base) {
    if (level < logLevel) return;
    char bufferUInt[sizeof(uint32_t)*8+1];
    utoa(value, bufferUInt, base);
    log(level, name, bufferUInt);
}
void Logger2::log(LogLevel level, const char *name, int64_t value,
                 uint8_t base) {
    if (level < logLevel) return;
    char bufferInt[sizeof(int64_t)*8+1];
    ltoa(value, bufferInt, base);
    log(level, name, bufferInt);
}
void Logger2::log(LogLevel level, const char *name, int32_t value,
                 uint8_t base) {
    if (level < logLevel) return;
    char bufferInt[sizeof(int32_t)*8+1];
    itoa(value, bufferInt, base);
    log(level, name, bufferInt);
}
void Logger2::log(LogLevel level, const char *name, double value,
                 unsigned int decimalPlaces) {
    if (level < logLevel) return;
    char bufferDouble[LOGGER_BUFFER_DOUBLE_SIZE];
    dtostrf(value, 0, decimalPlaces, bufferDouble);
}
void Logger2::log(LogLevel level, const char *name, uint8_t o1, uint8_t o2,
                 uint8_t o3, uint8_t o4) {
    if (level < logLevel) return;
    char *buffer = new char[LOGGER_BUFFER_SIZE];
    char prefix = prefixes[static_cast<int>(level)];
    sprintf(buffer, "%c %s: %d.%d.%d.%d", prefix, name, o1, o2, o3, o4);
    log(buffer);
}
