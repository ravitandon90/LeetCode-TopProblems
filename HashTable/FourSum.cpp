// Problem: https://leetcode.com/problems/4sum/

#include<string>
#include<stringstream>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

class FourSum {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> four_sum_result;
        unordered_set<string> result_set;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (i + 3 >= nums.size()) break;
            threeSums(nums, i + 1, target - nums[i], four_sum_result, result_set);
        }
        return four_sum_result;
    }
    
private:
    string toString(const vector<int>& nums) {
        string num_str;
        for (int i = 0; i < nums.size(); ++i) {
            num_str += to_string(nums[i]) + ":";
        }
        return num_str;
    }

    vector<vector<int>> twoSums(const vector<int>& nums, int start, int target) {
        int i = start; // Start Index.
        int j = nums.size() - 1; // End Index.
        vector<vector<int>> two_sum_result;
        while (i < j) {
            int sum = nums[i] + nums[j];
            if (sum < target) ++i;
            if (sum > target) --j;
            if (sum == target) {
                vector<int> result_vec;
                result_vec.push_back(nums[i]);
                result_vec.push_back(nums[j]);
                two_sum_result.push_back(result_vec);
                ++i;
                --j;
            }
        }
        return two_sum_result;
    }

    // @nums is assumed to be sorted.
    void threeSums(vector<int>& nums, int start, int target,
                   vector<vector<int>>& result, unordered_set<string>& result_set) {
        // Logic to find the triplet.
        for (int i = start; i < nums.size(); ++i) {
            vector<vector<int>> two_sums = twoSums(nums, i + 1, target - nums[i]);
            for (int j = 0; j < two_sums.size(); ++j) {
                // Holds the result as a vector.
                vector<int> result_vec;
                result_vec.push_back(two_sums[j][0]);
                result_vec.push_back(two_sums[j][1]);
                result_vec.push_back(nums[i]);
                // Semantics not great.
                result_vec.push_back(nums[start - 1]);
                // Stringify and compare to check if the result already exists.
                string result_str = toString(result_vec);
                if (result_set.find(result_str) == result_set.end()) {
                    // Insert into the results.
                    result.push_back(result_vec);
                    // Update the result set.
                    result_set.insert(result_str);
                }
            }
        }
    }
};