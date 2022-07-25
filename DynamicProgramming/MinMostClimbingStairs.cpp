// Problem: https://leetcode.com/problems/min-cost-climbing-stairs/

#include <vector>

using namespace std;

class MinMostClimbingStairs {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n_stairs = cost.size() + 1;
        int dp[n_stairs + 1];
        for (int i = 0; i <= n_stairs; ++i) dp[i] = 0;
        for (int i = 3; i <= n_stairs; ++i) {
            dp[i] = min(dp[i - 1] + cost[i - 2], dp[i - 2] + cost[i - 3]);
        }
        return dp[n_stairs];
    }
};