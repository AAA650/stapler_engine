//pthread.h Thread pools.

#define PTHREAD_H
#include "defse.h"
#include <vector>
#include <queue>
#include <memory>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <functional>
#include <stdexcept>
using namespace std;

class pthread {
	thread* thrs[4];
};
