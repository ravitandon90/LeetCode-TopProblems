// Problem: https://leetcode.com/problems/subarray-sum-equals-k/

#include<unordered_map>
#include<vector>

using namespace std;

class SubarraySum {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> s_map;
        int count = 0;
        int c_sum = 0;
        s_map[0] = 1;
        for (int i = 0; i < nums.size(); ++i) {
            c_sum += nums[i];
            int diff = c_sum - k;
            if (s_map.find(diff) != s_map.end()) { count += s_map[diff]; }
            s_map[c_sum]++;
        }
        return count;
    }
};