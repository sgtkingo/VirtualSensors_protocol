/**
 * @file logs.c
 * @brief Implementation of logging functions.
 * 
 * @copyright 2024 MTA
 * @author 
 * Ing. Jiri Konecny
 */

#include "logs.hpp"

std::string buildMessage(const char *format, ...) {
    char buffer[512];
    va_list args;
    va_start(args, format);
    vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);
    return std::string(buffer);
}

#ifdef ARDUINO_H
    #include <Arduino.h>  ///< Include Arduino Serial functions
#elif defined(STDIO_H)
    #include <stdio.h>    ///< Include standard I/O functions
#endif

void logMessage(const char *format, ...) {
    va_list args;
    va_start(args, format);

    #ifdef ARDUINO_H
        if(!Serial)
        {
            initLogger();
        }
        // Create a buffer for formatted output
        char buffer[256];
        vsnprintf(buffer, sizeof(buffer), format, args);
        Serial.println(buffer);  // Print via Arduino Serial
    #elif defined(STDIO_H)
        vprintf(format, args);  // Print via standard console
    #endif
    va_end(args);
}

void splashMessage(const char *format, ...) {
    va_list args;
    va_start(args, format);

    char buffer[256];
    vsnprintf(buffer, sizeof(buffer), format, args);

    #ifdef USE_LVGL
     show_splash_popup("Message", buffer, SPLASHER_TIMEOUT_MS); // Show splash for 5 seconds
    #else
     // If LVGL is not used, fallback to logMessage
     logMessage("Cant display splash: %s", buffer);
    #endif
    va_end(args);
}

void delay_ms(uint32_t ms) {
    #ifdef ARDUINO_H
        delay(ms); // Arduino delay
    #elif defined(_WIN32) || defined(_WIN64)
        Sleep(ms); // Windows sleep
    #else
        usleep(ms * 1000); // POSIX sleep
    #endif
}

void initLogger() {
    #ifdef ARDUINO_H
        Serial.begin(UART0_BAUDRATE); // Initialize Serial for Arduino
        unsigned long startTime = millis();

        while ((millis() - startTime) < UART0_INIT_TIMEOUT && !Serial) {
            // Wait for Serial to initialize or timeout
        }
    #endif
}

