#include <stdarg.h>
#include <stdio.h>
#include "log.h"

static const int32_t logVerbosity = MVE_LOG_DEBUG;

void mveLog(int32_t level, const char* format, ...) {
  if (level >= logVerbosity) {
    
    switch (level) {
      case MVE_LOG_DEBUG:
        printf("[DEBUG] ");
        break;

      case MVE_LOG_INFO:
        printf("[INFO] ");
        break;

      case MVE_LOG_WARN:
        printf("[WARN] ");
        break;

      case MVE_LOG_ERROR:
        printf("[ERROR] ");
        break;

      case MVE_LOG_FATAL:
        printf("[FATAL] ");
        break;
    }

    va_list args;
    va_start(args, format);
    vprintf(format, args);
    printf("\n");
    va_end(args);
  }
}
