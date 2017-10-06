
/**
 * main.cpp
 * David Selivanov <rtmpdavid@gmail.com>
 * on Monday 2016-05-30 14:38
 */

#include <engine.hpp>
#include <dgl_backend_sdl2.hpp>
#include <iostream>
#include <chrono>
#include <vector>
#include <thread>

int main()
{
  auto engine = DummyGL::instance();

  engine->init<DGL_SDL2_Backend>();
  engine->back_end()->create_window("a", 0, 0, 1024, 768, DGL_WINDOW_NONE);
  engine->main_loop();
  engine->quit();

  return 0;
}
