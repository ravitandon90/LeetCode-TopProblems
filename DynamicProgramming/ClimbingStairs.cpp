#include<unordered_map>

using namespace std;

class ClimbingStairs {
private:
    unordered_map<int, int> memory;

public:
    int climbStairs(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 2;
        if (memory.find(n) != memory.end()) return memory[n];
        memory[n] = climbStairs (n - 1) + climbStairs(n - 2);
        return memory[n];
    }
};