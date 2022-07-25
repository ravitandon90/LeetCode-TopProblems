// Problem: https://www.educative.io/blog/top-five-concurrency-interview-questions-for-software-engineers

#include <iostream>
#include <functional>
#include <unistd.h>
#include <mutex>
#include <condition_variable>

using namespace std;

class AsyncExecutor {
public:
  void execute(function<void()> callback) {
    sleep(10);
    callback();
  }
};

class SyncExecutor: public AsyncExecutor {
public:
  void execute(function<void()>callback) {
    function<void()> f = [this, callback] {
      callback();
      cond.notify_all();
    };
    AsyncExecutor::execute(f);
    unique_lock<mutex> lock(mtx_);
    cond.wait(lock);
  }

private:
  mutex mtx_;
  condition_variable cond;
};