// Problem: https://leetcode.com/problems/subsets/

#include <vector>

using namespace std;

class GenerateSubsets {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<bool> taken;
        taken.resize(nums.size(), false);
        vector<vector<int>> result;
        result.push_back({});
        generate(nums, taken, result, 0);
        return result;
    }

    void generate(const vector<int>& nums, vector<bool>& taken, vector<vector<int>>& result, int index) {
        if (index == nums.size()) {
            vector<int> r;
            generateResult(nums, taken, r);
            if (not r.empty()) result.push_back(r);
            return;
        }

        taken[index] = true;
        generate(nums, taken, result, index + 1);

        taken[index] = false;
        generate(nums, taken, result, index + 1);
    }

    void generateResult(const vector<int>& nums, const vector<bool>& taken, vector<int>& result) {
        for (int index = 0; index < nums.size(); ++index) {
            if (taken[index]) result.push_back(nums[index]);
        }
    }
};