///===-------------------------------------------------------------------------------===//
///
/// Part of Stapler Engine Project(aka. SE), under Apache License V2.0 .
/// See the LICENSE.md file for more information.
/// Copyright (c) 2026 AAA650. All Rights Reserved.
///
///===-------------------------------------------------------------------------------===//
///
/// SeWindow.h
/// This file contains the declaration of SeWindow, which is a abstraction layer
/// for window on different platforms.
///
///===-------------------------------------------------------------------------------===//

#ifndef SE_WINDOW_H
#define SE_WINDOW_H

#define GLFW_INCLUDE_VULKAN
#include "base/string.h"
#include "base/types.h"
#include "math/vector2.h"
#include <GLFW/glfw3.h>

namespace stapler_engine {
namespace core {
class Window {
protected:
  TString window_title_ = SE_TSTR("No Title");
  math::Vector2I window_size_ = math::Vector2I({1024, 600});

private:
  void initWindow();
  void initRender();

public:
  void setWindowTitle(TString Title) { window_title_ = Title; };
  TString getWindowTitle() { return window_title_; };
};
} // namespace core
} // namespace stapler_engine

#endif
