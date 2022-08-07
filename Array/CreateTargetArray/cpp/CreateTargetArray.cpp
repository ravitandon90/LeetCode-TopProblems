// Problem-Link: https://leetcode.com/problems/create-target-array-in-the-given-order/

#include<vector>

using namespace std;

class CreateTargetArray {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int max_size = nums.size();
        vector<int> target;
        if (max_size == 0) return target;
        for (int i = 0; i < max_size; ++i) {
            target.push_back(0);
        }
        for (int j = 0; j < max_size; ++j) {
            int target_index = index[j];
            // Push back all the rest of the elements.
            int pos = max_size - 1;
            while (pos > target_index) {
                target[pos] = target[pos - 1];
                --pos;
            }
            target[target_index] = nums[j];
        }
        return target;
    }
};