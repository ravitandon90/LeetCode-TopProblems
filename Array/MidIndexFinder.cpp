// Problem: https://leetcode.com/problems/find-the-middle-index-in-array/

#include <vector>

using namespace std;

class MidIndexFinder {
public:
    int findMiddleIndex(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int sum = 0;
        int sum_l = 0, sum_r = 0;
        for (int i = 0; i < nums.size(); ++i) sum += nums[i];        
        for (int i = 0; i < nums.size(); ++i) { 
            sum_r = sum - sum_l - nums[i];
            if (sum_r == sum_l) return i;
            sum_l += nums[i];
        }
        return -1;
    }
};