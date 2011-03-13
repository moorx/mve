#include <stdint.h>
#include <stdlib.h>
#include <glfw3.h>
#include "log.h"
#include "config.h"

int main(int32_t argc, const char** argv) {
  mveLog(MVE_LOG_INFO, "starting up");
  MVEconfig* config = mveInitConfig("config.lua");

  glfwInit();
  glfwOpenWindowHint(GLFW_WINDOW_NO_RESIZE, GL_TRUE);
  GLFWwindow window = glfwOpenWindow(config->window_width, config->window_height,
                                     GLFW_WINDOWED, config->window_title, NULL);

  while (glfwIsWindow(window)) {
    glfwPollEvents();
    glfwSwapBuffers();
  }

  glfwTerminate();

  return 0;
}
