// Problem: https://leetcode.com/problems/target-sum/

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;


class TargetSum {
public:    
    string toString(int index, int target) {
        return to_string(index) + ":" + to_string(target);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string, int> dp;
        string key = toString(nums.size() - 1, target);
        dp[key] = findTargetSumWaysUtil(nums, nums.size() - 1, target, dp);
        return dp[key];        
    }
    
    int findTargetSumWaysUtil(const vector<int>& nums, int index, 
                              int target, unordered_map<string, int>& dp) {                
        if (index < 0) {
            if (target == 0) return 1;
            return 0;
        }            
        string key = toString(index, target);
        if (dp.find(key) != dp.end()) return dp[key];
        dp[key] = 
            findTargetSumWaysUtil(nums, index - 1, target + nums[index], dp) +
            findTargetSumWaysUtil(nums, index - 1, target - nums[index], dp);
        return dp[key];        
    }
};