///===-------------------------------------------------------------------------------===//
///
/// Part of Stapler Engine Project(aka. SE), under Apache License V2.0 .
/// See the LICENSE.md file for more information.
/// Copyright (c) 2026 AAA650. All Rights Reserved.
///
///===-------------------------------------------------------------------------------===//
///
/// base/base.h
/// This file contains macros for stapler engine base.
///
///===-------------------------------------------------------------------------------===//

#ifndef SE_CORE_THREAD_POOL_H
#define SE_CORE_THREAD_POOL_H

#include "base/base.h"
#include <atomic>
#include <condition_variable>
#include <mutex>
#include <queue>
#include <thread>

namespace stapler_engine {
namespace core {
class ThreadPool {
private:
  struct Worker {
    ThreadPool *pool;
    Size id;
  };

  struct Task {
    void (*callback)(void *);
    void *arguments;
  };

  std::atomic<Size> workers_count_;
  std::atomic<std::queue<Task>> task_queue_;
};
} // namespace core
} // namespace stapler_engine

#endif
