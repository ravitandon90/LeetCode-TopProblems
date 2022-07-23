// Problem-Link: https://leetcode.com/problems/sort-colors/

#include<vector>
using namespace std;

class ColorSorter {
public:
    void sortColors(vector<int>& nums) {
        int num[3];
        for (int i = 0; i < 3; ++i) {
            num[i] = 0;
        }
        for (int i = 0;  i<  nums.size(); ++i) {
            num[nums[i]]++;
        }
        int curr_idx = 0;
        for (int i = 0; i < 3; ++i){
            for (int j = 0; j < num[i]; ++j) {
                nums[curr_idx]  = i;
                curr_idx++;
            }
        }
    }
};