// Problem: https://leetcode.com/problems/the-dining-philosophers/
// Dining Philosophers

#include<vector>
#include<mutex>
#include<condition_variable>
#include<functional>


class DiningPhilosophers {
public:
    DiningPhilosophers() {
        spoons.resize(NUM_PHILOSOPHERS, true);
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {

        {
            std::unique_lock<std::mutex> lock(mtx_);
            cond.wait(lock, [this, philosopher] {
                return (spoons[philosopher] && spoons[(philosopher + 1) % NUM_PHILOSOPHERS]);
            });
            spoons[philosopher] = false;
            spoons[(philosopher + 1) % NUM_PHILOSOPHERS] = false;
            pickLeftFork();
            pickRightFork();

        }
        eat();
        {
            std::unique_lock<std::mutex> lock(mtx_);
            spoons[philosopher] = true;
            spoons[(philosopher + 1) % NUM_PHILOSOPHERS] = true;
            putLeftFork();
            putRightFork();
            cond.notify_all();
        }
    }

private:
    vector<bool> spoons;
    int NUM_PHILOSOPHERS = 5;
    std::mutex mtx_;
    std::condition_variable cond;
};