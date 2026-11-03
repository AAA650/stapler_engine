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
#include <algorithm>
#include <condition_variable>
#include <exception>
#include <functional>
#include <list>
#include <memory>
#include <mutex>
#include <queue>
#include <thread>

namespace stapler_engine {
namespace core {
class ThreadPool {
private:
  enum class Status { kRun = 0, kStop };

  struct Exceptions {
    std::exception err;
    std::function<void()> task;
  };

  struct PoolData {
    std::queue<std::function<void()>> pool_tasks;
    std::queue<Exceptions> pool_exceptions;
    std::mutex pool_lock;
    std::mutex exception_lock;
    std::mutex thread_lock;
    std::condition_variable notificator;
  };

  class Worker {
  private:
    struct WorkerData {
      Status worker_status;
      std::shared_ptr<PoolData> pool_data;
    };

    static void WorkerMain(std::shared_ptr<WorkerData> worker_data) {
      std::unique_lock<std::mutex> pool_locker(
          worker_data->pool_data->pool_lock, std::defer_lock);
      for (;;) {
        pool_locker.lock();
        if (worker_data->worker_status == Status::kStop) {
          break;
        }
        if (worker_data->pool_data->pool_tasks.empty()) {
          worker_data->pool_data->notificator.wait(pool_locker);
          pool_locker.unlock();
          continue;
        }
        std::function<void()> task = worker_data->pool_data->pool_tasks.front();
        worker_data->pool_data->pool_tasks.pop();
        pool_locker.unlock();
        if (!task)
          continue;
        try {
          task();
        } catch (const std::exception &err) {
          std::unique_lock<std::mutex> exception_locker(
              worker_data->pool_data->exception_lock);
          worker_data->pool_data->pool_exceptions.push(Exceptions{err, task});
        }
      }
      return;
    }

    std::shared_ptr<WorkerData> worker_data_;

  public:
    Worker(const std::shared_ptr<PoolData> &pool_data) {
      worker_data_ = std::make_shared<WorkerData>();
      worker_data_->worker_status = Status::kRun;
      worker_data_->pool_data = pool_data;
      std::thread worker_thread(WorkerMain, worker_data_);
      worker_thread.detach();
      return;
    }

    ~Worker() {
      std::unique_lock pool_locker(worker_data_->pool_data->pool_lock);
      worker_data_->worker_status = Status::kStop;
      pool_locker.unlock();
      worker_data_->pool_data->notificator.notify_all();
    }
  };
  std::shared_ptr<PoolData> pool_data_;
  std::list<Worker> worker_list_;

public:
  void CreateThread(Size cnt = 1) {
    std::unique_lock<std::mutex> thread_locker(pool_data_->thread_lock);
    for (Size i = 0; i < cnt; i++) {
      worker_list_.emplace_back(pool_data_);
    }
    return;
  }

  void KillThread(Size cnt = 1) {
    std::unique_lock<std::mutex> thread_locker(pool_data_->thread_lock);
    cnt = std::min(cnt, worker_list_.size());
    for (Size i = 0; i < cnt; i++) {
      worker_list_.pop_back();
    }
    return;
  }

  void PushTask(std::function<void()> task) {
    Size task_cnt = 0;
    std::unique_lock<std::mutex> pool_locker(pool_data_->pool_lock);
    pool_data_->pool_tasks.push(task);
    task_cnt = pool_data_->pool_tasks.size();
    pool_locker.unlock();
    if (task_cnt > 1)
      pool_data_->notificator.notify_all();
    else
      pool_data_->notificator.notify_one();
    return;
  }

  Exceptions GetException() {
    std::unique_lock<std::mutex> exception_locker(pool_data_->exception_lock);
    Exceptions err = pool_data_->pool_exceptions.front();
    pool_data_->pool_exceptions.pop();
    return err;
  }

  ThreadPool() {
    pool_data_ = std::make_shared<PoolData>();
    CreateThread(1);
  }
  ThreadPool(const ThreadPool &) = delete;
  ThreadPool &operator=(const ThreadPool &) = delete;

  ~ThreadPool() { KillThread(worker_list_.size()); }
};
} // namespace core
} // namespace stapler_engine

#endif
