// Problem: https://leetcode.com/problems/sum-of-all-subset-xor-totals/

#include <vector>

class SubsetXORSum {
public:
    int subsetXORSum(vector<int>& nums) {
        vector<bool> subset;
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) subset.push_back(false);
        getNext(0, nums, subset, sum);
        return sum;
    }

private:    
    void getNext(int index, vector<int>& nums, vector<bool>& subset, int& sum) {
        if (index >= subset.size()) return;
        subset[index] = true;
        getNext(index + 1, nums, subset, sum);
        sum += getXOR(nums, subset);
        subset[index] = false;
        getNext(index + 1, nums, subset, sum);
    }
    
    int getXOR(const vector<int>& nums, const vector<bool>& subset) {
        int result = 0;
        for (int i = 0; i < subset.size(); ++i) {
            if (subset[i]) result ^= nums[i];
        }
        return result;
    }
};