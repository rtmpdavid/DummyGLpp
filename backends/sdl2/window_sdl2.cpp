
/**
 * window_sdl2.cpp
 * David Selivanov <rtmpdavid@gmail.com>
 * on Monday 2016-05-30 2:47
 */

#include "window_sdl2.hpp"

window_sdl2::window_sdl2()
{
  wnd = 0;
}

window_sdl2::window_sdl2(window_sdl2 &&other) noexcept
{
  wnd = other.wnd;
  other.wnd = 0;
}

window_sdl2::window_sdl2(const std::string& title, int x, int y, int w, int h, int flags)
{
  wnd = SDL_CreateWindow(title.c_str(), x, y, w, h, flags);
  if(!wnd)
    throw DGL_sdl2_exception();
}

window_sdl2::~window_sdl2()
{
  if(wnd)
    SDL_DestroyWindow(wnd);
}
