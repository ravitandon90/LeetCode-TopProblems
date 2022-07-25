// Problem: https://leetcode.com/problems/sort-array-by-parity/

#include <vector>

using namespace std;

class SortArrayByParity {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int odd = nums.size() - 1;
        int even = 0;
        while (even < odd) {
            if ((nums[even] % 2) == 0) { ++even; continue; }
            if ((nums[odd] % 2) == 1) { --odd; continue; }
            // Even has an odd digit.
            // Odd has an even digit.
            // Even is less than odd.
            swap(nums, odd, even);
        }
        return nums;
    }

private:
    void swap(vector<int>& nums, int i1, int i2) {
        int tmp = nums[i1];
        nums[i1] = nums[i2];
        nums[i2] = tmp;
    }
};