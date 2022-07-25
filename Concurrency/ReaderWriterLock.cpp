// Problem: https://www.educative.io/blog/top-five-concurrency-interview-questions-for-software-engineers

#include <iostream>
#include <mutex>
#include <condition_variable>

using namespace std;

class ReaderWriterLock {
public:
  ReaderWriterLock(): num_readers_(0), num_writers_(0) {}

  void AcquireReadLock() {
    mtx_.lock();
    ++num_readers_;
    mtx_.unlock();
  }

  void AcquireWriteLock() {
    std::unique_lock<mutex> lock(mtx_);
    cond.wait(lock, [this] {
      return num_readers_ == 0;
    });
    ++num_writers_;
  }

  void ReleaseReadLock() {
    mtx_.lock();
    --num_readers_;
    if (num_readers_ == 0) cond.notify_all();
    mtx_.unlock();
  }

  void ReleaseWriteLock() {
    --num_writers_;
    mtx_.unlock();
  }

private:
  std::condition_variable cond;
  std::mutex mtx_;
  int num_readers_;
  int num_writers_;
};

