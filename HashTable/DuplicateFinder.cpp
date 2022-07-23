// Problem-Link: https://leetcode.com/problems/contains-duplicate/

#include<unordered_set>

using namespace std;

class DuplicateFinder {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> nums_set;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums_set.find(nums.at(i)) != nums_set.end()) return true;
            nums_set.insert(nums.at(i));
        }
        return false;
    }
};