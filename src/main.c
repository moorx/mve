#include <stdint.h>
#include <stdlib.h>
#include <glfw3.h>
#include "log.h"
#include "config.h"

#define MVE_CONFIG_FILE_NAME "config.lua"

int main(int32_t argc, const char** argv) {
  mveLog(MVE_LOG_INFO, "starting up");
  MVEconfig* config = mveInitConfig(MVE_CONFIG_FILE_NAME);

  glfwInit();
  glfwOpenWindowHint(GLFW_WINDOW_NO_RESIZE, GL_TRUE);
  GLFWwindow window = glfwOpenWindow(config->window_width, config->window_height,
                                     GLFW_WINDOWED, config->window_title, NULL);

  while (glfwIsWindow(window)) {
    glfwSwapBuffers();
    glfwPollEvents();
  }

  glfwTerminate();

  return 0;
}
