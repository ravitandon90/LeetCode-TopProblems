// Problem: https://www.educative.io/blog/top-five-concurrency-interview-questions-for-software-engineers

#include <iostream>
#include <mutex>
#include <condition_variable>

using namespace std;

class Semaphore {
public:
  Semaphore(int count): count_(count) {}

  void acquire() {
    unique_lock<mutex> lock(mtx_);
    cond.wait(lock, [this] {
      return count_ > 0;
    });
    --count_;
  }

  void signal() {
    unique_lock<mutex> lock(mtx_);
    ++count_;
  }

private:
  condition_variable cond;
  mutex mtx_;
  int count_;
};

class UberRiderProblem {
public:
  UberRiderProblem(): democrats_(0), republicans_(0),
    democrats_waiting_(0), republicans_waiting_(0) {}
  void drive() {}
  void seated() { drive(); }
  void rideDemocrat() {
    {
      unique_lock<mutex> lock(mtx_);
      ++democrats_;
    }
    {
      unique_lock<mutex> lock(mtx_);
      if (democrats_ >= 4) {
        democrats_waiting_.signal();
        democrats_waiting_.signal();
        democrats_waiting_.signal();
      } else if (republicans_ >= 2 && democrats_ >= 2) {
        democrats_waiting_.signal();
        republicans_waiting_.signal();
        republicans_waiting_.signal();
      } else {
        democrats_waiting_.acquire();
      }
    }
    {
      unique_lock<mutex> lock(mtx_);
      --democrats_;
      seated();
    }
  }
  void rideRepublican() {
    {
      unique_lock<mutex> lock(mtx_);
      ++republicans_;
    }
    {
      unique_lock<mutex> lock(mtx_);
      if (republicans_ >= 4) {
        republicans_waiting_.signal();
        republicans_waiting_.signal();
        republicans_waiting_.signal();
      } else if (republicans_ >= 2 && democrats_ >= 2) {
        republicans_waiting_.signal();
        democrats_waiting_.signal();
        democrats_waiting_.signal();
      } else {
        republicans_waiting_.acquire();
      }
    }
    {
      unique_lock<mutex> lock(mtx_);
      --republicans_;
      seated();
    }
  }

private:
  mutex mtx_;
  int democrats_;
  int republicans_;
  Semaphore democrats_waiting_;
  Semaphore republicans_waiting_;
};