// Problem: https://www.educative.io/blog/top-five-concurrency-interview-questions-for-software-engineers

#include <iostream>
#include <condition_variable>
#include <mutex>

using namespace std;

class Semaphore {
  public: 
    Semaphore(int count): count_(count) {}
    void acquire() {
      unique_lock<mutex> lock(mtx_);
      cond_.wait(lock, [this] {
        return count_ > 0;
      });
      --count_;
    }
    void release() {
      unique_lock<mutex> lock(mtx_);
      ++count_;
    }

  private:
    int count_;
    mutex mtx_;
    condition_variable cond_;
};

class BarberShop {
  public:
    BarberShop(int num_chairs): empty_chairs_(num_chairs), 
                                is_barber_asleep_(false), 
                                customer_waiting_(0) {}
    

    void barberThreadRun() {
      while (true) {
        {
          unique_lock<mutex> lock(mtx_);
          barber_asleep_.wait(lock, [this] {
            return num_customers_ > 0;
          });
          is_barber_asleep_ = false;
        }
        // No-Op. giveHairCut();
        customer_waiting_.release();
      }
    }   

    void customerEnters() {
      {
        unique_lock<mutex> lock(mtx_);
        if (empty_chairs_ == 0) return;
        // (empty_chairs_ > 0) {        
        ++num_customers_;  
        --empty_chairs_;          
        if (is_barber_asleep_) {          
          barber_asleep_.notify_one();
        }      
        // Customer waits on a chair.
        customer_waiting_.acquire();
      }      
      customerLeaves();
    }

  void customerLeaves() {    
    unique_lock<mutex> lock(mtx_);
    --num_customers_;    
  }

  private:
    mutex mtx_;
    // Indicates the number of chairs that are free.
    int empty_chairs_;
    // Indicates the number of customers to be served.
    int num_customers_;
    Semaphore customer_waiting_;
    bool is_barber_asleep_;
    condition_variable barber_asleep_;
};