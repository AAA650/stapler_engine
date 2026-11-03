//
// Created by aaa650 on 2026/8/24.
//

#ifndef SE_MAIN_SESSION_H
#define SE_MAIN_SESSION_H

#include <iostream>
#include <stdexcept>
#include <vector>

namespace stapler_engine {
namespace main {
class Session {
private:
  void init() {};

  void loop() {};

  void clean() {};

public:
  void Run() {
    // Initalize
    init();
    // Main loop
    // Clean up
  }
};
} // namespace main
} // namespace stapler_engine

#endif // STAPLER_ENGINE_SESSION_H
