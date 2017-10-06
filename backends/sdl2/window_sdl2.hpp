
/**
 * window_sdl.hpp
 * Created by David Selivanov <rtmpdavid@gmail.com>
 * on Monday 2016-05-30 22:47
 */

#ifndef WINDOW_SDL2_HPP
#define WINDOW_SDL2_HPP

#include <dgl_logger.hpp>
#include <SDL2/SDL.h>
#include <string>

#include "sdl2.hpp"

class window_sdl2 : sdl2_subsystem<SDL_INIT_VIDEO>
{
  SDL_Window* wnd;
public:
  window_sdl2();
  window_sdl2(window_sdl2 &&) noexcept;
  window_sdl2(const std::string& title, int x, int y, int w, int h, int flags);
  ~window_sdl2();
};

#endif /* WINDOW_SDL2_HPP */

