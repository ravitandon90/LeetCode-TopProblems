// Problem: https://leetcode.com/problems/search-insert-position/

#include <vector>

using namespace std;

class SearchInsertPosition {
public:
    int searchInsert(vector<int>& nums, int target) {
        int pivot, left = 0, right = nums.size() - 1;
        while (left <= right) {
            pivot = left + (right - left) / 2;
            if (target == nums[pivot]) return pivot;
            if (target < nums[pivot]) right = pivot - 1;
            else left = pivot + 1;
        }
        return left;        
    }
};