// Problem: https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/

#include <vector>

using namespace std;

class MinDiff {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if (n < 5) return 0;
        sort(nums.begin(), nums.end());
        int ans = INT_MAX;
        // Case-I: Kill 3 largest.
        ans = min(ans, nums[n - 4] - nums[0]);
        // Case-II: Kill 3 smallest.
        ans = min(ans, nums[n - 1] - nums[3]);
        // Case-III: Kill 2 largest, 1 smallest.
        ans = min(ans, nums[n - 3] - nums[1]);
        // Case-IV: Kill 2 smallest, 1 largest.
        ans = min(ans, nums[n - 2] - nums[2]);
        return ans;
    }
};