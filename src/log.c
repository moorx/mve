#include <stdarg.h>
#include <pez.h>
#include "log.h"

static const MVELogLevel logVerbosity = MVE_LOG_DEBUG;

void mveLog(MVELogLevel level, const char* message) {
  if (level >= logVerbosity) {
    
    switch (level) {
      case MVE_LOG_DEBUG:
        PezDebugString("[DEBUG] ");
        break;

      case MVE_LOG_INFO:
        PezDebugString("[INFO] ");
        break;

      case MVE_LOG_WARN:
        PezDebugString("[WARN] ");
        break;

      case MVE_LOG_ERROR:
        PezDebugString("[ERROR] ");
        break;

      case MVE_LOG_FATAL:
        PezDebugString("[FATAL] ");
        break;
    }

    PezDebugString(message);
  }
}

void mveLogFormat(MVELogLevel level, const char* format, ...) {
  va_list args;
  va_start(args, format);

  char msg[1024] = {0};
  vsnprintf(msg, countof(msg), format, args);
  mveLog(level, msg);
}
