
/**
 * sdl2.cpp
 * David Selivanov <rtmpdavid@gmail.com>
 * on Tuesday 2016-06-14 01:32
 */

#include "dgl_backend_sdl2.hpp"
#include "event_sdl2.hpp"
#include "sdl2.hpp"

DGL_SDL2_Backend::DGL_SDL2_Backend() :
  window_counter(0)
{
  elog(log_lvl::dbg, "Creating SDL2 backend");
  elog(log_lvl::dbg, "Initializing SDL2");
  if(SDL_Init(0))
    throw DGL_sdl2_exception();
}

DGL_SDL2_Backend::~DGL_SDL2_Backend()
{
  elog(log_lvl::dbg, "Destroying SDL2 backend");
  elog(log_lvl::dbg, "Initializing SDL2");
  SDL_Quit();
}

int DGL_SDL2_Backend::create_window(const std::string &title, int x, int y, int w, int h, int flags)
{
  elog(log_lvl::dbg, "Creating an SDL2 window");
  int id = ++window_counter;

  int sdl2_window_flags = SDL_WINDOW_OPENGL;

  if(flags & DGL_WINDOW_FULLSCREEN)
  {
    flags^=DGL_WINDOW_FULLSCREEN;
    sdl2_window_flags|=SDL_WINDOW_FULLSCREEN;
  }
  if(flags & DGL_WINDOW_RESIZEABLE)
  {
    flags^=DGL_WINDOW_RESIZEABLE;
    sdl2_window_flags|=SDL_WINDOW_RESIZABLE;
  }

  if(flags != 0)
  {
    elog(log_lvl::wrn, "Unrecognized flag(s) were used ({})", flags);
  }

  windows.insert(std::make_pair(id, window_sdl2(title, x, y, w, h, sdl2_window_flags)));
  return id;
}

void DGL_SDL2_Backend::destroy_window(int window_index)
{
  elog(log_lvl::dbg, "Destroying an SDL2 window");
  windows.erase(window_index);
}

std::string DGL_SDL2_Backend::backend_name()
{
  return "SDL2";
}

std::vector<DGLEventSource*> DGL_SDL2_Backend::event_sources()
{
  return std::vector<DGLEventSource*>{new DGL_SDL2_Event};
}

std::vector<int> DGL_SDL2_Backend::window_id_list()
{
  std::vector<int> window_list;
  for(auto &window : windows)
    window_list.push_back(window.first);

  return window_list;
}
