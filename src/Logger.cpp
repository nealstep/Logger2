#include "Logger.h"

void Logger::setPrint(Print &loggerPrint) {
    print = &loggerPrint;
    usePrint = true;
}

void Logger::setLevel(LogLevel level) { logLevel = level; }

void Logger::log(const char *msg) {
    if (usePrint) {
        print->println(msg);
    }
    if (useMQTT) {
        ;  // Not implemented
    }
}
void Logger::log(LogLevel level, const char *msg) {
    if (level < logLevel) return;
    log(msg);
}
void Logger::log(LogLevel level, const char *name, const char *value) {
    if (level < logLevel) return;
    char *buffer = new char[LOGGER_BUFFER_SIZE];
    char prefix = prefixes[static_cast<int>(level)];
    sprintf(buffer, "%c %s: %s", prefix, name, value);
    log(buffer);
    delete buffer;
}
void Logger::log(LogLevel level, const char *name, uint64_t value,
                 uint8_t base) {
    if (level < logLevel) return;
}
void Logger::log(LogLevel level, const char *name, uint32_t value,
                 uint8_t base) {
    if (level < logLevel) return;
}
void Logger::log(LogLevel level, const char *name, int64_t value,
                 uint8_t base) {
    if (level < logLevel) return;
}
void Logger::log(LogLevel level, const char *name, int32_t value,
                 uint8_t base) {
    if (level < logLevel) return;
}
void Logger::log(LogLevel level, const char *name, double value,
                 unsigned int decimalPlaces) {
    if (level < logLevel) return;
}
void Logger::log(LogLevel level, const char *name, uint8_t o1, uint8_t o2,
                 uint8_t o3, uint8_t o4) {
    if (level < logLevel) return;
    char *buffer = new char[LOGGER_BUFFER_SIZE];
    char prefix = prefixes[static_cast<int>(level)];
    sprintf(buffer, "%c %s: %d.%d.%d.%d", prefix, name, o1, o2, o3, o4);
    log(buffer);
    delete buffer;
}
