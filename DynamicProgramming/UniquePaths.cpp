// Problem: https://leetcode.com/problems/unique-paths/

#include <string>
#include <unordered_map>

using namespace std;

class UniquePaths {
public:
    int uniquePaths(int m, int n) {
        unordered_map<string, int> memo;
        return uniquePathsInt(m - 1, n - 1, memo);
    }

private:    
    int uniquePathsInt(int m, int n, unordered_map<string, int>& memo) {
        if (m == 0 && n == 0) return 1;
        if (m < 0 || n < 0) return 0;
        const string key = std::to_string(m) + ":" + std::to_string(n);
        if (memo.find(key) != memo.end()) return memo[key];
        int num_paths = uniquePathsInt(m - 1, n, memo) + uniquePathsInt(m , n -1, memo);
        memo[key] = num_paths;
        return num_paths;
    }
};