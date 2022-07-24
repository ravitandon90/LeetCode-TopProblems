// Problem: https://leetcode.com/problems/move-zeroes/

#include <vector>

using namespace std;

class MoveZeroes {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.size() < 2) return;
        int zi = -1;
        int nzi = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (zi == -1 && nums[i] == 0) zi = i;
            if (zi == -1) continue;
            if (nzi == -1 && nums[i] != 0) nzi = i;
            // Nothing to swap so continue.
            if (zi == -1 || nzi == -1) continue;
            // Swap the numbers.
            nums[zi] = nums[nzi];
            nums[nzi] = 0;
            // Need to find the next non-zero number's index.
            nzi = -1;
            zi++;
        }
    }
};