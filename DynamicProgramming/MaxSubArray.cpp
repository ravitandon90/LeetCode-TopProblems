// Problem-Link: https://leetcode.com/problems/maximum-subarray/

#include<algorithm>
#include<vector>

using namespace std;

class MaxSubArray {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        // At least one element is present.
        int currSum = nums[0];
        int maxSum = currSum;
        for (int index = 1; index < nums.size(); ++index) {
            int currNum = nums[index];
            int newSum = currSum + currNum;
            currSum = std::max(newSum, currNum);
            maxSum = std::max(maxSum, currSum);
        }
        return maxSum;
    }
};