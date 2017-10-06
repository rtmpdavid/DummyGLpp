
/**
 * event_base.hpp
 * Created by David Selivanov <rtmpdavid@gmail.com>
 * on Tuesday 2016-05-31 17:04
 */

#ifndef EVENT_BASE_HPP
#define EVENT_BASE_HPP

#include <chrono>
#include "dgl_bits/dgl_time.hpp"
#include "dgl_bits/dgl_keys.hpp"

enum class DGLEventType { none, quit, input_key_up, input_key_down, input_mouse_button, input_mouse_movement, window };
enum class DGLInputType { key, mouse_button, mouse_movement, touch, gesture };
enum DGLWindowN { WINDOW_NONE = -1, WINDOW_0, WINDOW_1, WINDOW_2, WINDOW_3, WINDOW_4, WINDOW_5, WINDOW_6, WINDOW_7, WINDOW_8};
enum class DGLMouseButton { left, middle, right };
enum class DGLMouseButtonType{ up, down };

typedef struct DGLEventCommon {
  DGLEventType event_type;
  hclock::time_point timestamp;
}DGLEventCommon;

typedef struct DGLEventQuit {
  DGLEventType event_type;
  hclock::time_point timestamp;
}DGLEventQuit;

typedef struct DGLWindowEvent {
  DGLEventType event_type;
  hclock::time_point timestamp;
  int window_n; 
}DGLWindowEvent;

typedef struct DGLInputKey {
  DGLEventType event_type;
  hclock::time_point timestamp;
  int window_n; 
  DGLKeyID id;
  bool has_text;
  char text[32];
}DGLInputKey;

typedef struct DGLInputMouseButton {
  DGLEventType event_type;
  hclock::time_point timestamp;
  int window_n; 
  DGLMouseButton button;
  DGLMouseButtonType type;
}DGLInputMouseButton;

typedef struct DGLMouseMovement {
  DGLEventType event_type;
  hclock::time_point timestamp;
  int window_n; 
  int x;
  int y;
  int dx;
  int dy;
}DGLMouseMovement;

typedef union DGLEvent {
  DGLEventType type;
  DGLEventCommon common;
  DGLEventQuit quit;
  DGLWindowEvent window;
  DGLInputKey key;

  DGLEvent();
}DGLEvent;

#endif /* EVENT_BASE_HPP */
