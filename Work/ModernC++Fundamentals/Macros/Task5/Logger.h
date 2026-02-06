#ifndef LOGGER_H // checks whether LOGGER_H is not defined
#define LOGGER_H // defines LOGGER_H

#include <stdio.h>

/* Log levels */
#define LOG_ERROR 1 // Error level
#define LOG_WARN  2 // Warning level
#define LOG_INFO  3 // Info level
#define LOG_DEBUG 4 // Debug level

/* Default log level */
#ifndef LOG_LEVEL // checks whether LOG_LEVEL is not defined 
#define LOG_LEVEL LOG_ERROR // sets default log level to ERROR
#endif

/* Logging macro */
#define LOG(level, message)                   \
    do {                                       \
        if (level <= LOG_LEVEL) {              \
            if (level == LOG_ERROR)            \
                printf("ERROR: %s\n", message); \
            else if (level == LOG_WARN)        \
                printf("WARN: %s\n", message);  \
            else if (level == LOG_INFO)        \
                printf("INFO: %s\n", message);  \
            else if (level == LOG_DEBUG)       \
                printf("DEBUG: %s\n", message); \
        }                                      \
    } while (0)

#endif