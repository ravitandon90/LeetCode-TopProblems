// Problem: https://leetcode.com/problems/random-pick-index/
#include<unordered_map>
#include<vector>

using namespace std;

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */

class ReservoirSampling {
public:
    // Generates a random number between [0, k-1] with equal probability.
    int randK(vector<int>& array) {
        if (array.empty()) return -1;
        // Copy elements in the reservoir.
        int k = array[0];

        // Replacing the index in the reservoir.
        for (int i = 1; i <= array.size(); ++i) {
            int r =  rand() % i;
            if (r == 0) {
                k = array[i - 1];
            }
        }
        return k;

    }

    Solution(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            _arr[nums[i]].push_back(i);
        }
    }

    int pick(int target) {
        unordered_map<int, vector<int>>::iterator it;
        it = _arr.find(target);
        if (it == _arr.end()) return -1;
        return randK(it->second);
    }

private:
    unordered_map<int, vector<int>> _arr;
};