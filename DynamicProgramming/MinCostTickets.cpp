// Problem: https://leetcode.com/problems/minimum-cost-for-tickets/

#include <vector>

using namespace std;

class MinCostTickets {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // Maximum number of days.
        int dp[366];
        dp[0] = 0;
        int prev_day = 0;
        for (int i = 0; i < days.size(); ++i) {
            int day = days[i];
            // Filling all the days in between.
            // If a day doesn't exist, then the cost of that day remains the same.
            for (int j = prev_day; j < day; ++j) {
                dp[j] = dp[prev_day];
            }
            // dp[i] = min(cost[0] + dp[i - 1], cost[1] + dp[i-7], cost[2] + dp[i-30])
            dp[day] = getMin(costs[0] + dp[max(0, day - 1)],
                             costs[1] + dp[max(0, day - 7)],
                             costs[2] + dp[max(0, day - 30)]);
            prev_day = day;
        }
        return dp[days.back()];
    }

private:
    int getMin(int a, int b, int c) {
        return min(a, min(b, c));
    }
};