
/**
 * dgl_logger.cpp
 * David Selivanov <rtmpdavid@gmail.com>
 * on Tuesday 2016-06-14 02:46
 */

#include <chrono>

#include "dgl_logger.hpp"
#include "dgl_bits/dgl_time.hpp"

const hclock::time_point eng_start = hclock::now();

fmt::Color elog_begin(log_lvl level, fmt::MemoryWriter & out)
{
  fmt::Color out_color;
  const char* log_level = "";
  switch (level)
  {
  case log_lvl::dbg:
    log_level = "DBG";
    out_color = fmt::CYAN;
    break;
  case log_lvl::err:
    log_level = "ERR";
    out_color = fmt::RED;
    break;
  case log_lvl::inf:
    log_level = "INF";
    out_color = fmt::WHITE;
    break;
  case log_lvl::wrn:
    log_level = "WRN";
    out_color = fmt::YELLOW;
    break;
  }
  auto now = std::chrono::duration_cast<std::chrono::microseconds>(hclock::now() - eng_start).count();

  out.write("{:0>10}[{:0>3}]", now, log_level);

  return out_color;
}
