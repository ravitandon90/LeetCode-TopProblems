// Problem: https://leetcode.com/problems/third-maximum-number/

#include<algorithm>
#include<vector>
#include<unordered_set>

using namespace std;

class ThirdMaxFinder {
public:
    int thirdMax(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        unordered_set<int> nums_set;
        for (int index = 0; index < nums.size(); ++index) {
            nums_set.insert(nums[index]);
        }
        vector<int> new_nums;
        unordered_set<int>::iterator it;
        for (it = nums_set.begin(); it != nums_set.end(); ++it) {
            new_nums.push_back(*it);
        }
        std::sort(new_nums.begin(), new_nums.end(), greater());
        if (new_nums.size() < 3) return new_nums[0];
        return new_nums[2];
    }
};