
/**
 * sdl2.hpp
 * Created by David Selivanov <rtmpdavid@gmail.com>
 * on Tuesday 2016-06-14 01:29
 */

#ifndef DGL_BACKEND_SDL2_HPP
#define DGL_BACKEND_SDL2_HPP

#include <unordered_map>

#include <dgl_backend.hpp>
#include "window_sdl2.hpp"

class DGL_SDL2_Backend : public DGLBackend {
  int window_counter;
  std::unordered_map<int, window_sdl2> windows;
public:
  DGL_SDL2_Backend();
  ~DGL_SDL2_Backend();

  int create_window(const std::string &title, int x, int y, int w, int h, int flags);
  void destroy_window(int window_index);
  std::string backend_name();
  std::vector<DGLEventSource*> event_sources();
  std::vector<int> window_id_list();
};

#endif /* DGL_BACKEND_SDL2_HPP */
