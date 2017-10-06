
/**
 * event_sdl2.hpp
 * Created by David Selivanov <rtmpdavid@gmail.com>
 * on Saturday 2016-07-09 18:59
 */

#include <dgl_event_source.hpp>

#ifndef EVENT_SDL2_HPP
#define EVENT_SDL2_HPP

class DGL_SDL2_Event : public DGLEventSource {
public:
  DGL_SDL2_Event();
  ~DGL_SDL2_Event();

  bool next_event(DGLEvent&);
  std::vector<DGLEvent> get_events();
};

#endif /* EVENT_SDL2_HPP */
