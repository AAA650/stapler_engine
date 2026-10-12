//
// Created by aaa650 on 2026/8/24.
//

#ifndef SE_SESSION_H
#define SE_SESSION_H

#include <iostream>
#include <stdexcept>
#include <vector>

namespace stapler_engine {
namespace main {
class SeSession {
private:
  void _init_() {};

  void _loop_() {};

  void _clean_up_() {};

public:
  void run_() {
    // Initalize
    _init_();
    // Main loop
    // Clean up
  }
};
} // namespace main
} // namespace stapler_engine

#endif // STAPLER_ENGINE_SESSION_H
