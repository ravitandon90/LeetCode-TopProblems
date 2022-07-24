// Problem: https://leetcode.com/problems/remove-duplicates-from-sorted-array/

#include <vector>

using namespace std;

class DuplicateRemover {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();
        int index = 0;
        int j = 0;
        for (int j = 0; j < nums.size() - 1; ++j) {
            if (nums[j] != nums[j + 1]) {
                nums[index] = nums[j];
                ++index;
            }
        }
        if (index < nums.size()) {
            nums[index] = nums[nums.size() - 1];
            ++index;
        }
        return index;
    }
};