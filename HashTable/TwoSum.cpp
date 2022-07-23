// Problem-Link: https://leetcode.com/problems/two-sum/

#include<vector>
#include<unordered_map>

using namespace std;

class TwoSum {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> sums;
        vector<int> results;
        for (int i = 0; i < nums.size(); ++i) {
            int rem = target - nums[i];
              sums[rem] = i;
            
        }
        for (int i = 0; i < nums.size(); ++i) {
            // Finding the 
            if (sums.find(nums[i]) != sums.end()) {
                // Handling the case when the same element is searced.
                if (sums[nums[i]] != i) {
                   // Ensuring that the results are sorted.
                   // Pushing the smaller element first.
                   results.push_back(std::min(i, sums[nums[i]]));
                   // Pushing the bigger element second.
                   results.push_back(std::max(i, sums[nums[i]]));
                   break;
                }
            }
        }
    return results;
    }
};