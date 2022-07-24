// Problem: https://leetcode.com/problems/majority-element/

#include<unordered_map>
#include<vector>

using namespace std;

class MajorityElement {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> num_count;
        int max_count = 0;
        int max_num = 0;
        for (int i = 0; i < nums.size(); ++i) {
            num_count[nums[i]]++;
            if (max_count < num_count[nums[i]]) {
                max_count = num_count[nums[i]];
                max_num = nums[i];
            }
        }
        return max_num;
    }
};