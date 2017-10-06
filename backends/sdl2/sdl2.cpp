
/**
 * sdl2.cpp
 * David Selivanov <rtmpdavid@gmail.com>
 * on Monday 2016-05-30 23:35
 */

#include "sdl2.hpp"

DGL_sdl2_exception::DGL_sdl2_exception() :
  str(SDL_GetError())
{
}

const char * DGL_sdl2_exception::what() const noexcept
{
  return str;
}


