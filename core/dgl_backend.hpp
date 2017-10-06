
/**
 * backend.hpp
 * Created by David Selivanov <rtmpdavid@gmail.com>
 * on Tuesday 2016-05-31 16:53
 */

#ifndef DGL_BACKEND_HPP
#define DGL_BACKEND_HPP

// class DGLBackend;

#include <vector>
#include <string>
#include "dgl_event.hpp"
#include "dgl_event_source.hpp"

enum DGLWindowFlags { DGL_WINDOW_NONE = 0, DGL_WINDOW_FULLSCREEN = 1, DGL_WINDOW_RESIZEABLE = 2};

class DGLBackend {
public:
  DGLBackend()
  { }

  virtual ~DGLBackend()
  { }

  virtual int create_window(const std::string &title, int x, int y, int w, int h, int flags) = 0;
  virtual void destroy_window(int window_index) = 0;

  virtual std::string backend_name() = 0;
  virtual std::vector<DGLEventSource*> event_sources() = 0;
  virtual std::vector<int> window_id_list() = 0;
};

#endif /* DGL_BACKEND_HPP */
