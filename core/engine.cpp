
/**
 * engine.cpp
 * David Selivanov <rtmpdavid@gmail.com>
 * on Monday 2016-05-30 12:38
 */

#include "engine.hpp"
#include "dgl_bits/dgl_time.hpp"

#include <exception>

DummyGL *DummyGL::engine_instance;

DummyGL::DummyGL()
{  
  state = eng_state::running;
}

DummyGL::~DummyGL()
{
  elog(log_lvl::inf, "Exiting");
  if(backend)
    backend.reset(nullptr);
}

DGLBackend* DummyGL::back_end()
{
  if(backend)
    return backend.get();
  else
    throw std::runtime_error("Engine is not initialized");
}

void DummyGL::main_loop()
{
  elog(log_lvl::inf, "Starting main loop");

  while(state != eng_state::done)
  {
    //check events(input, signals, net, w/e)
    //send events to scene
    //step scene
    //draw scene, if sufficient time has passed
    for(auto event_source : event_sources)
    {
      DGLEvent event;
      while(event_source->next_event(event))
      {
	if(event.type == DGLEventType::quit)
	  state = eng_state::done;
	if(event.type == DGLEventType::input_key_down)
	{
	  if(event.key.has_text)
	    elog(log_lvl::inf, "{}", event.key.text);
	}
      }
    }
  }
}

DummyGL* DummyGL::instance()
{
  if(!engine_instance)
    engine_instance = new DummyGL();

  return engine_instance;
}

void DummyGL::quit()
{
  elog(log_lvl::inf, "Uninitializing DummyGL");
  for(auto id : backend->window_id_list())
    backend->destroy_window(id);

  if(engine_instance)
    delete engine_instance;
}

