
/**
 * dgl_logger.hpp
 * Created by David Selivanov <rtmpdavid@gmail.com>
 * on Tuesday 2016-06-14 02:46
 */

#ifndef DGL_LOGGER_HPP
#define DGL_LOGGER_HPP

#include <fmt/format.h>

enum class log_lvl { dbg, inf, wrn, err};

fmt::Color elog_begin(log_lvl level, fmt::MemoryWriter & out);

template <typename... Args>
void elog(log_lvl level, const std::string& format, const Args& ... args) {
  fmt::MemoryWriter out;
  auto color = elog_begin(level, out);
  out.write(format, args...);
  out.write("\n");
  fmt::print_colored(color, out.str());
}

#endif /* DGL_LOGGER_HPP */
