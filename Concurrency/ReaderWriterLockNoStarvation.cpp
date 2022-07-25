// Problem: https://www.educative.io/blog/top-five-concurrency-interview-questions-for-software-engineers

#include <iostream>
#include <mutex>
#include <condition_variable>

using namespace std;

class ReaderWriterLockNoStarvation {
public:
  ReaderWriterLockNoStarvation(): num_readers_(0), num_writers_(0) {}

  void AcquireReadLock() {
    {
      std::unique_lock<mutex> lock(mtx_);
      writer_waiting.wait(lock, [this] {
        return writer_waiting_ == false;
      });
    }
    {
      std::unique_lock<mutex> lock(mtx_);
      ++num_readers_;
    }
  }

  void AcquireWriteLock() {
    {
      std::unique_lock<mutex> lock(mtx_);
      writer_waiting_ = true;
    }
    {
      std::unique_lock<mutex> lock(mtx_);
      wait_on_reader.wait(lock, [this] {
        return num_readers_ == 0;
      });
      ++num_writers_;
    }
  }

  void ReleaseReadLock() {
    unique_lock<mutex> lock(mtx_);
    --num_readers_;
    wait_on_reader.notify_all();
  }

  void ReleaseWriteLock() {
    unique_lock<mutex> lock(mtx_);
    --num_writers_;
    writer_waiting_ = false;
    writer_waiting.notify_all();
  }

private:
  std::condition_variable wait_on_reader;
  std::condition_variable writer_waiting;
  std::mutex mtx_;
  bool writer_waiting_;
  int num_readers_;
  int num_writers_;
};