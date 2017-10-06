
/**
 * dgl_input.hpp
 * Created by David Selivanov <rtmpdavid@gmail.com>
 * on Tuesday 2016-06-14 01:05
 */

#ifndef DGL_INPUT_HPP
#define DGL_INPUT_HPP

#include "dgl_event.hpp"
#include <vector>

class DGLInput {
  DGLInputEvent next_event;

public:
  DGLInput();

  virtual std::vector<DGLInputEvent> get();

  virtual ~DGLInput();
};

#endif /* DGL_INPUT_HPP */
