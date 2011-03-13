#ifndef LOG_H_
#define LOG_H_

#include <stdint.h>

enum { MVE_LOG_DEBUG, MVE_LOG_INFO, MVE_LOG_WARN, MVE_LOG_ERROR, MVE_LOG_FATAL };

void mveLog(int32_t level, const char* format, ...);

#endif  // LOG_H_
