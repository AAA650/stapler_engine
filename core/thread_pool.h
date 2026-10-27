///===-------------------------------------------------------------------------------===//
///
/// Part of Stapler Engine Project(aka. SE), under Apache License V2.0 .
/// See the LICENSE.md file for more information.
/// Copyright (c) 2026 AAA650. All Rights Reserved.
///
///===-------------------------------------------------------------------------------===//
///
/// core/thread_pool.h
/// This file contains declaration of ThreadPool.
///
///===-------------------------------------------------------------------------------===//

#ifndef SE_CORE_THREAD_POOL_H
#define SE_CORE_THREAD_POOL_H

#include "base/base.h"
#include <condition_variable>
#include <list>
#include <memory>
#include <mutex>
#include <pthread.h>
#include <queue>
#include <thread>

namespace stapler_engine {
namespace core {
class ThreadPool {
private:
  class Worker {
  private:
    enum class Status { kRun = 0, kStop };

    struct WorkerData {
      ThreadPool *pool = nullptr;
      Status status = Status::kRun;
      std::mutex worker_lock;
    };

    static void workerMain(std::shared_ptr<WorkerData> data) {
      std::unique_lock<std::mutex> locker(data->worker_lock, std::defer_lock);
      for (;;) {
        locker.lock();
        if (data->status == Status::kStop) {
          break;
        }
        locker.unlock();
        std::unique_lock<std::mutex> pool_locker(data->pool->lock_,
                                                 std::try_to_lock);
        if (data->pool->task_list_.size() == 0) {
          data->pool->notificator_.wait(pool_locker);
          continue;
        }
        void (*task)() = data->pool->task_list_.front();
        data->pool->task_list_.pop();
        pool_locker.unlock();
        task();
      }
      locker.unlock();
      return;
    }

    std::shared_ptr<WorkerData> data_;

  public:
    Worker(ThreadPool *pool) {
      data_ = std::make_shared<WorkerData>();
      data_->pool = pool;
      data_->status = Status::kRun;
      std::thread worker_thread(workerMain, data_);
      worker_thread.detach();
    }

    ~Worker() {
      std::unique_lock<std::mutex> locker(data_->worker_lock, std::try_to_lock);
      data_->status = Status::kStop;
    }
  };

private:
  std::queue<void (*)()> task_list_;
  std::mutex lock_;
  std::condition_variable notificator_;
  std::list<Worker> workers_;

public:
  void PushTask(void (*task)()) {
    std::unique_lock<std::mutex> pool_locker(lock_, std::try_to_lock);
    task_list_.push(task);
    pool_locker.unlock();
    notificator_.notify_one();
    return;
  }

  void OpenThread() { workers_.emplace_back(this); }

  void CloseThread() {
    workers_.pop_back();
    notificator_.notify_all();
  }
};
} // namespace core
} // namespace stapler_engine

#endif
