#ifndef CONFIG_H_
#define CONFIG_H_

#include <stdint.h>

typedef struct {
  uint16_t window_width;
  uint16_t window_height;
  char* window_title;
} MVEconfig;

MVEconfig* mveInitConfig(const char* filename);

#endif  // CONFIG_H_
