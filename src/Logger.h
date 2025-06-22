#ifndef LOGGER_H
#define LOGGER_H

#include <Arduino.h>

#if defined(ESP8266)
#include <ESP8266WiFi.h>
#elif defined(ESP32)
#include <WiFi.h>
#else
#error "Not supported"
#endif  // ESP8266 or ESP32

#define LOGGER_BUFFER_SIZE 256
#define LOGGER_DEFAULT_BASE 10
#define LOGGER_DEFAULT_DECIMAL_PLACES 2

class Logger {
   public:
    enum LogLevel { DEBUG = 0, INFO, WARNING, ERROR, VALUE, COUNT };

    void setPrint(Print &loggerPrint);
    void setLevel(LogLevel level);

    void log(LogLevel level, const char *msg);
    void log(LogLevel level, const char *name, const char *value);
    void log(LogLevel level, const char *name, uint64_t value,
             uint8_t base = LOGGER_DEFAULT_BASE);
    void log(LogLevel level, const char *name, uint32_t value,
             uint8_t base = LOGGER_DEFAULT_BASE);
    void log(LogLevel level, const char *name, uint16_t value,
             uint8_t base = LOGGER_DEFAULT_BASE) {
        log(logLevel, name, (uint32_t)value, base);
    }
    void log(LogLevel level, const char *name, uint8_t value,
             uint8_t base = LOGGER_DEFAULT_BASE) {
        log(logLevel, name, (uint32_t)value, base);
    }
    void log(LogLevel level, const char *name, int64_t value,
             uint8_t base = LOGGER_DEFAULT_BASE);
    void log(LogLevel level, const char *name, int32_t value,
             uint8_t base = LOGGER_DEFAULT_BASE);
    void log(LogLevel level, const char *name, int16_t value,
             uint8_t base = LOGGER_DEFAULT_BASE) {
        log(logLevel, name, (int32_t)value, base);
    }
    void log(LogLevel level, const char *name, int8_t value,
             uint8_t base = LOGGER_DEFAULT_BASE) {
        log(logLevel, name, (int32_t)value, base);
    }
    void log(LogLevel level, const char *name, double value,
             unsigned int decimalPlaces = LOGGER_DEFAULT_DECIMAL_PLACES);
    void log(LogLevel level, const char *name, float value,
             unsigned int decimalPlaces = LOGGER_DEFAULT_DECIMAL_PLACES) {
        log(logLevel, name, (double)value, decimalPlaces);
    }
    void log(LogLevel level, const char *name, uint8_t o1, uint8_t o2,
             uint8_t o3, uint8_t o4);

    // convenience routines
    void debug(const char *msg) { log(DEBUG, msg); }
    void debug(const char *name, const char *val) { log(DEBUG, name, val); }
    void debug(const char *name, uint64_t val,
               uint8_t base = LOGGER_DEFAULT_BASE) {
        log(DEBUG, name, val, base);
    }
    void debug(const char *name, uint32_t val,
               uint8_t base = LOGGER_DEFAULT_BASE) {
        log(DEBUG, name, val, base);
    }
    void debug(const char *name, uint16_t val,
               uint8_t base = LOGGER_DEFAULT_BASE) {
        log(DEBUG, name, (uint32_t)val, base);
    }
    void debug(const char *name, uint8_t val,
               uint8_t base = LOGGER_DEFAULT_BASE) {
        log(DEBUG, name, (uint32_t)val, base);
    }
    void debug(const char *name, int64_t val,
               uint8_t base = LOGGER_DEFAULT_BASE) {
        log(DEBUG, name, val, base);
    }
    void debug(const char *name, int32_t val,
               uint8_t base = LOGGER_DEFAULT_BASE) {
        log(DEBUG, name, val, base);
    }
    void debug(const char *name, int16_t val,
               uint8_t base = LOGGER_DEFAULT_BASE) {
        log(DEBUG, name, (int32_t)val, base);
    }
    void debug(const char *name, int8_t val,
               uint8_t base = LOGGER_DEFAULT_BASE) {
        log(DEBUG, name, (int32_t)val, base);
    }
    void debug(const char *name, double val,
               unsigned int decimalPlaces = LOGGER_DEFAULT_DECIMAL_PLACES) {
        log(DEBUG, name, val, decimalPlaces);
    }
    void debug(const char *name, float val,
               unsigned int decimalPlaces = LOGGER_DEFAULT_DECIMAL_PLACES) {
        log(DEBUG, name, (double)val, decimalPlaces);
    }
    void info(const char *msg) { log(INFO, msg); }
    void info(const char *name, const char *val) { log(INFO, name, val); }
    void info(const char *name, uint64_t val,
              uint8_t base = LOGGER_DEFAULT_BASE) {
        log(INFO, name, val, base);
    }
    void info(const char *name, uint32_t val,
              uint8_t base = LOGGER_DEFAULT_BASE) {
        log(INFO, name, val, base);
    }
    void info(const char *name, uint16_t val,
              uint8_t base = LOGGER_DEFAULT_BASE) {
        log(INFO, name, (uint32_t)val, base);
    }
    void info(const char *name, uint8_t val,
              uint8_t base = LOGGER_DEFAULT_BASE) {
        log(INFO, name, (uint32_t)val, base);
    }
    void info(const char *name, int64_t val,
              uint8_t base = LOGGER_DEFAULT_BASE) {
        log(INFO, name, val, base);
    }
    void info(const char *name, int32_t val,
              uint8_t base = LOGGER_DEFAULT_BASE) {
        log(INFO, name, val, base);
    }
    void info(const char *name, int16_t val,
              uint8_t base = LOGGER_DEFAULT_BASE) {
        log(INFO, name, (int32_t)val, base);
    }
    void info(const char *name, int8_t val, uint8_t base = LOGGER_DEFAULT_BASE) {
        log(INFO, name, (int32_t)val, base);
    }
    void info(const char *name, double val,
              unsigned int decimalPlaces = LOGGER_DEFAULT_DECIMAL_PLACES) {
        log(INFO, name, val, decimalPlaces);
    }
    void info(const char *name, float val,
              unsigned int decimalPlaces = LOGGER_DEFAULT_DECIMAL_PLACES) {
        log(INFO, name, (double)val, decimalPlaces);
    }
    void info(const char *name, uint8_t o1, uint8_t o2, uint8_t o3, uint8_t o4) {
        log(INFO, name, o1, o2, o3, o4);
    }
    void warning(const char *msg) { log(WARNING, msg); }
    void warning(const char *name, const char *val) { log(WARNING, name, val); }
    void warning(const char *name, uint64_t val,
                 uint8_t base = LOGGER_DEFAULT_BASE) {
        log(WARNING, name, val, base);
    }
    void warning(const char *name, uint32_t val,
                 uint8_t base = LOGGER_DEFAULT_BASE) {
        log(WARNING, name, val, base);
    }
    void warning(const char *name, uint16_t val,
                 uint8_t base = LOGGER_DEFAULT_BASE) {
        log(WARNING, name, (uint32_t)val, base);
    }
    void warning(const char *name, uint8_t val,
                 uint8_t base = LOGGER_DEFAULT_BASE) {
        log(WARNING, name, (uint32_t)val, base);
    }
    void warning(const char *name, int64_t val,
                 uint8_t base = LOGGER_DEFAULT_BASE) {
        log(WARNING, name, val, base);
    }
    void warning(const char *name, int32_t val,
                 uint8_t base = LOGGER_DEFAULT_BASE) {
        log(WARNING, name, val, base);
    }
    void warning(const char *name, int16_t val,
                 uint8_t base = LOGGER_DEFAULT_BASE) {
        log(WARNING, name, (int32_t)val, base);
    }
    void warning(const char *name, int8_t val,
                 uint8_t base = LOGGER_DEFAULT_BASE) {
        log(WARNING, name, (int32_t)val, base);
    }
    void warning(const char *name, double val,
                 unsigned int decimalPlaces = LOGGER_DEFAULT_DECIMAL_PLACES) {
        log(WARNING, name, val, decimalPlaces);
    }
    void warning(const char *name, float val,
                 unsigned int decimalPlaces = LOGGER_DEFAULT_DECIMAL_PLACES) {
        log(WARNING, name, (double)val, decimalPlaces);
    }
    void error(const char *msg) { log(ERROR, msg); }
    void error(const char *name, const char *val) { log(ERROR, name, val); }
    void error(const char *name, uint64_t val,
               uint8_t base = LOGGER_DEFAULT_BASE) {
        log(ERROR, name, val, base);
    }
    void error(const char *name, uint32_t val,
               uint8_t base = LOGGER_DEFAULT_BASE) {
        log(ERROR, name, val, base);
    }
    void error(const char *name, uint16_t val,
               uint8_t base = LOGGER_DEFAULT_BASE) {
        log(ERROR, name, (uint32_t)val, base);
    }
    void error(const char *name, uint8_t val,
               uint8_t base = LOGGER_DEFAULT_BASE) {
        log(ERROR, name, (uint32_t)val, base);
    }
    void error(const char *name, int64_t val,
               uint8_t base = LOGGER_DEFAULT_BASE) {
        log(ERROR, name, val, base);
    }
    void error(const char *name, int32_t val,
               uint8_t base = LOGGER_DEFAULT_BASE) {
        log(ERROR, name, val, base);
    }
    void error(const char *name, int16_t val,
               uint8_t base = LOGGER_DEFAULT_BASE) {
        log(ERROR, name, (int32_t)val, base);
    }
    void error(const char *name, int8_t val,
               uint8_t base = LOGGER_DEFAULT_BASE) {
        log(ERROR, name, (int32_t)val, base);
    }
    void error(const char *name, double val,
               unsigned int decimalPlaces = LOGGER_DEFAULT_DECIMAL_PLACES) {
        log(ERROR, name, val, decimalPlaces);
    }
    void error(const char *name, float val,
               unsigned int decimalPlaces = LOGGER_DEFAULT_DECIMAL_PLACES) {
        log(ERROR, name, (double)val, decimalPlaces);
    }
    void value(const char *msg) { log(VALUE, msg); }
    void value(const char *name, const char *val) { log(VALUE, name, val); }
    void value(const char *name, uint64_t val,
               uint8_t base = LOGGER_DEFAULT_BASE) {
        log(VALUE, name, val, base);
    }
    void value(const char *name, uint32_t val,
               uint8_t base = LOGGER_DEFAULT_BASE) {
        log(VALUE, name, val, base);
    }
    void value(const char *name, uint16_t val,
               uint8_t base = LOGGER_DEFAULT_BASE) {
        log(VALUE, name, (uint32_t)val, base);
    }
    void value(const char *name, uint8_t val,
               uint8_t base = LOGGER_DEFAULT_BASE) {
        log(VALUE, name, (uint32_t)val, base);
    }
    void value(const char *name, int64_t val,
               uint8_t base = LOGGER_DEFAULT_BASE) {
        log(VALUE, name, val, base);
    }
    void value(const char *name, int32_t val,
               uint8_t base = LOGGER_DEFAULT_BASE) {
        log(VALUE, name, val, base);
    }
    void value(const char *name, int16_t val,
               uint8_t base = LOGGER_DEFAULT_BASE) {
        log(VALUE, name, (int32_t)val, base);
    }
    void value(const char *name, int8_t val,
               uint8_t base = LOGGER_DEFAULT_BASE) {
        log(VALUE, name, (int32_t)val, base);
    }
    void value(const char *name, double val,
               unsigned int decimalPlaces = LOGGER_DEFAULT_DECIMAL_PLACES) {
        log(VALUE, name, val, decimalPlaces);
    }
    void value(const char *name, float val,
               unsigned int decimalPlaces = LOGGER_DEFAULT_DECIMAL_PLACES) {
        log(VALUE, name, (double)val, decimalPlaces);
    }

   private:
    bool usePrint = false;
    bool useMQTT = false;
    LogLevel logLevel = DEBUG;
    Print *print;
    void log(const char *msg);
    const char prefixes[static_cast<int>(COUNT)] = {'%', '#', '*', '!',
                                                            '$'};
};

#endif  // LOGGER_H