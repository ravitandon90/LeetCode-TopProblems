// Problem: https://leetcode.com/problems/partition-equal-subset-sum/

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class PartitionEqualSubsetSum {
public:
    bool canPartition(vector<int>& nums) {
        int sum = getSum(nums);
        unordered_map<string, bool> dp;
        if ((sum % 2)  == 1) return false;
        return canPartitionUtil(nums, nums.size() - 1, sum / 2, dp);
    }

    bool canPartitionUtil(vector<int>& nums, int index, int target, unordered_map<string, bool>& dp) {
        if (target == 0) return true;
        if (target < 0 || index < 0) return false;
        string key = to_string(index) + ":" + to_string(target);
        if (dp.find(key) != dp.end()) return dp[key];
        dp[key] =
            canPartitionUtil(nums, index - 1, target - nums[index], dp) ||
            canPartitionUtil(nums, index - 1, target, dp);
        return dp[key];
    }

    int getSum(vector<int>& nums) {
        int sum = 0;
        for (int elem : nums) sum += elem;
        return sum;
    }
};