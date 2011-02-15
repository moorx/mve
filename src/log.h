typedef enum { MVE_LOG_DEBUG, MVE_LOG_INFO, MVE_LOG_WARN, MVE_LOG_ERROR,
  MVE_LOG_FATAL } MVELogLevel;

void mveLog(MVELogLevel level, const char* format, ...);
