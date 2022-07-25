// Problem: https://leetcode.com/problems/egg-drop-with-2-eggs-and-n-floors/

#include <bits/stdc++.h>

using namespace std;

class EggDrop {
public:
    int twoEggDrop(int n) {
        memset(dp, -1, sizeof(dp));
        return eggDropUtil(2, n);
    }

private:
    int eggDropUtil(int eggs, int floors) {
        if (floors <= 1) return floors;
        if (floors == 2) return 2;
        if (eggs == 1) return floors;
        if (dp[eggs][floors] != -1) return dp[eggs][floors];

        int result = INT_MAX;
        for (int i = 1; i <= floors; ++i) {
            result = min(result, 1 +
                         max(eggDropUtil(eggs - 1, i - 1), // Egg breaks on Ith floor.
                             eggDropUtil(eggs, floors - i))); // Egg doesn't break on the Ith floor.
        }
        dp[eggs][floors] = result;
        return dp[eggs][floors];
    }
    
    int dp[3][1001];
};