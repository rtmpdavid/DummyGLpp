
/**
 * sdl2.hpp
 * Created by David Selivanov <rtmpdavid@gmail.com>
 * on Monday 2016-05-30 23:34
 */

#ifndef SDL2_HPP
#define SDL2_HPP

#include <SDL2/SDL.h>
#include <mutex>

#include <dgl_logger.hpp>

class DGL_sdl2_exception : public std::exception {
  const char* str;
public:
  DGL_sdl2_exception();
  virtual const char *what() const noexcept;
};

template<int N>
class sdl2_subsystem {
  static int users;
  static std::mutex mtx;
public:

  sdl2_subsystem() {
    if(!users)
    {
      elog(log_lvl::dbg, "Initializing subsystem {}", N);
      SDL_InitSubSystem(N);
    }
    users++;

  }

  ~sdl2_subsystem() {
    std::lock_guard<std::mutex> lock(mtx);
    users--;  
    if(!users)
    {
      elog(log_lvl::dbg, "Quitting subsystem {}", N);
      SDL_QuitSubSystem(N);
    }
  }
};

template<int N>
std::mutex sdl2_subsystem<N>::mtx;

template<int N>
int sdl2_subsystem<N>::users(0);

#endif /* SDL2_HPP */
