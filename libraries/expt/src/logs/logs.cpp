/**
 * @file logs.c
 * @brief Implementation of logging functions.
 * 
 * @copyright 2024 MTA
 * @author 
 * Ing. Jiri Konecny
 */

#ifndef LOGS_HPP
#define LOGS_HPP

#include "logs.hpp"

std::string buildMessage(const char *format, ...) {
    char buffer[256];
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

    #ifdef SPLASHER_H
     show_splash_popup("Message", buffer, 3000); // Show splash for 3 seconds
    #endif   

    va_end(args);
}

#endif // LOGS_HPP

