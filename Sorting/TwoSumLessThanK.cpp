// Problem: https://leetcode.com/problems/two-sum-less-than-k/

#include<algorithm>
#include<vector>

using namespace std;

class TwoSumLessThanK {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        int max_sum = -1;
        int i = 0;
        int j = nums.size() - 1;
        sort(nums.begin(), nums.end());
        while(i<j) {
            int curr_sum = nums[i] + nums[j];
            if (curr_sum >= k) --j;
            if (curr_sum < k) {
                if (curr_sum > max_sum) max_sum = curr_sum;
                ++i;
            }                 
        }        
        return max_sum;
    }
};