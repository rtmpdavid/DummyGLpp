
/**
 * event_sdl2.cpp
 * David Selivanov <rtmpdavid@gmail.com>
 * on Saturday 2016-07-09 19:02
 */

#include <SDL2/SDL.h>
#include <string.h>

#include "event_sdl2.hpp"
#include <dgl_logger.hpp>

DGL_SDL2_Event::DGL_SDL2_Event()
{
  // SDL_StartTextInput();
  // SDL_StopTextInput();
}

DGL_SDL2_Event::~DGL_SDL2_Event()
{
}

bool DGL_SDL2_Event::next_event(DGLEvent& e)
{
  SDL_Event sdl_event;
  if(SDL_PollEvent(&sdl_event))
  {
    switch(sdl_event.type)
    {
    case SDL_QUIT:
      e.type = DGLEventType::quit;
      break;
    case SDL_KEYDOWN:
      e.type = DGLEventType::input_key_up;
      // e.key.id = (DGLKeyID)sdl_event.key.keysym.scancode;
      elog(log_lvl::dbg, "keydown {}", sdl_event.key.keysym.scancode);
      if(SDL_PeepEvents(&sdl_event, 1, SDL_PEEKEVENT, SDL_FIRSTEVENT, SDL_LASTEVENT)
	 && 
	 (sdl_event.type == SDL_TEXTINPUT))
      {
	SDL_PollEvent(&sdl_event);
	elog(log_lvl::dbg, "input {} {}", sdl_event.text.windowID, sdl_event.text.text);
	e.key.has_text = true;
	strcpy(e.key.text, sdl_event.text.text);
      }
      else
      {
	e.key.has_text = false;
      }
      break;
    case SDL_KEYUP:
      e.type = DGLEventType::input_key_down;
      elog(log_lvl::dbg, "keyup {}", sdl_event.key.keysym.scancode);
      break;
    case SDL_TEXTINPUT:
      elog(log_lvl::dbg, "input {} {}", sdl_event.text.windowID, sdl_event.text.text);
      break;
    case SDL_TEXTEDITING:
      elog(log_lvl::dbg, "edit {}", sdl_event.text.text);
      break;
    default:
      e.type = DGLEventType::none;
      break;
    }
    return true;
  }
  else
    return false;
}

std::vector<DGLEvent> DGL_SDL2_Event::get_events()
{
  return std::vector<DGLEvent>();
}

