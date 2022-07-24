// Problem: https://leetcode.com/problems/monotonic-array/

#include <vector>

using namespace std;

class IsMonotone {
public:
    bool isMonotonic(vector<int>& nums) {
        if (nums.size() <= 2) return true;
        bool sign[2];
        memset(sign, false, sizeof(sign));
        for (int i = 1; i < nums.size(); ++i) {
            int diff = nums[i] - nums[i - 1];
            if (diff < 0) sign[0] = true;
            else if (diff > 0) sign[1] = true;
            if (sign[0] && sign[1]) return false;
        }
        return true;
    }
};