
/**
 * engine.h
 * Created by David Selivanov <rtmpdavid@gmail.com>
 * on Monday 2016-05-30 12:33
 */

#ifndef ENGINE_H
#define ENGINE_H

class DummyGL;

#include <chrono>
#include <memory>

#include "dgl_logger.hpp"
#include "dgl_bits/dgl_time.hpp"
#include "dgl_backend.hpp"
#include "dgl_event_source.hpp"

class DummyGL {
private:
  std::unique_ptr<DGLBackend> backend;
  std::vector<DGLEventSource*> event_sources;

  enum class eng_state { running, paused, done };

  DummyGL::eng_state state;

  static DummyGL *engine_instance;

public:
  static DummyGL* instance();

  template <typename BackEnd>
  void init()
  {
    elog(log_lvl::inf, "Initializing DummyGL");

    try {
      backend.reset(new BackEnd);
    }
    catch (std::exception &e) {
      elog(log_lvl::err, "Failed to initialize backend: {}",
	   e.what());
    }
    int a;
    for(auto event_source : backend->event_sources())
      event_sources.push_back(event_source);
  }

  void main_loop();
  void quit();

  DGLBackend* back_end();
private:
  DummyGL();
  ~DummyGL();
};

#endif /* ENGINE_H */
