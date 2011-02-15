#include <pez.h>
#include "log.h"

const char* PezInitialize(int width, int height) {
  mveLog(MVE_LOG_DEBUG, "starting mve\n");
  return "mve";
}

void PezRender() {
}

void PezUpdate(unsigned int ms) {
}

void PezHandleMouse(int x, int y, int action) {
}
