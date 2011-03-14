#include <stdlib.h>
#include <string.h>
#include <ljit.h>
#include "config.h"
#include "log.h"

static MVEconfig* mveCreateConfig() {
  MVEconfig* config = (MVEconfig*)malloc(sizeof(MVEconfig));
  config->window_width = 640;
  config->window_height = 400;
  config->window_title = "mve";
  return config;
}

static void mveLoadConfig(const char* filename, MVEconfig* config) {
  mveLog(MVE_LOG_INFO, "loading config from %s", filename);

  lua_State* lua = luaL_newstate();
  int32_t error = luaL_dofile(lua, filename);

  if (error == 1) {
    mveLog(MVE_LOG_ERROR, "unable to load config file - %s",
           lua_tostring(lua, -1));
    lua_close(lua);
    return;
  }

  lua_getglobal(lua, "window_width");
  lua_getglobal(lua, "window_height");
  lua_getglobal(lua, "window_title");

  if (lua_isnumber(lua, -3)) {
    config->window_width = (int16_t)lua_tonumber(lua, -3);
    mveLog(MVE_LOG_DEBUG, "<config> window width is %d", config->window_width);
  }

  if (lua_isnumber(lua, -2)) {
    config->window_height = (int16_t)lua_tonumber(lua, -2);
    mveLog(MVE_LOG_DEBUG, "<config> window height is %d", config->window_height);
  }

  if (lua_isstring(lua, -1)) {
    size_t length;
    const char* title = lua_tolstring(lua, -1, &length);
    config->window_title = (char*)malloc(length);
    memcpy(config->window_title, title, length);
    mveLog(MVE_LOG_DEBUG, "<config> window title is '%s'", config->window_title);
  }

  mveLog(MVE_LOG_INFO, "config loaded");
}

MVEconfig* mveInitConfig(const char* filename) {
  MVEconfig* config = mveCreateConfig();
  mveLoadConfig(filename, config);
  return config;
}
