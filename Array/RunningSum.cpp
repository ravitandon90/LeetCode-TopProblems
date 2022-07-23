// Problem-Link: https://leetcode.com/problems/running-sum-of-1d-array/

#include<vector>

using namespace std;

class RunningSum {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> running_sums;
        int curr_sum = 0;
        for (int index = 0; index < nums.size(); ++index) {        
            running_sums.push_back(curr_sum + nums[index]);
            curr_sum += nums[index];
        }
        return running_sums;
    }
};