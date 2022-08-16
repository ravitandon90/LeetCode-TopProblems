// Problem: https://leetcode.com/problems/longest-continuous-increasing-subsequence/

#include <vector>

using namespace std;

class LCISFinder {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int len = 1;
        int max_len = 1;
        for (int idx = 0; idx < (int)(nums.size() - 1); ++idx) {
            if (nums[idx] < nums[idx + 1]) { ++len; max_len = max(max_len, len); }
            else len = 1;
        }
        return max_len;
    }
};