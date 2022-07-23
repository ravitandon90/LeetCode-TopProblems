#include<vector>

using namespace std;

class BinarySearch {
public:
    int search(vector<int>& nums, int target) {
        return searchInt(nums, 0, nums.size() - 1, target);
    }

private:
    int searchInt(const vector<int>& nums, int s, int e, int target) {
        if (s > e) return -1;
        if (s < 0 || e >= nums.size()) return -1;
        if (s == e) {
            if (nums.at(s) == target) return s;
            return -1;
        }
        int mid_index = (s + e) / 2;
        int mid = nums.at(mid_index);
        if (target == mid) return mid_index;
        if (mid > target) return searchInt(nums, s, mid_index - 1, target);
        return searchInt(nums, mid_index + 1, e, target);
    }
};