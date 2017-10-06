
/**
 * dgl_event_source.hpp
 * Created by David Selivanov <rtmpdavid@gmail.com>
 * on Saturday 2016-07-09 18:36
 */

#ifndef DGL_EVENT_SOURCE_HPP
#define DGL_EVENT_SOURCE_HPP

#include <vector>
#include "dgl_event.hpp"

class DGLEventSource {
public:
  DGLEventSource();
  virtual ~DGLEventSource();

  virtual bool next_event(DGLEvent&) = 0;
  virtual std::vector<DGLEvent> get_events() = 0;
};

#endif /* DGL_EVENT_SOURCE_HPP */
