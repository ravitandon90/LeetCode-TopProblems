// Problem: https://leetcode.com/problems/continuous-subarray-sum/

#include <unordered_map>
#include <vector>

using namespace std;

class ContinuousSubarraySum {
public:
	bool checkSubarraySum(vector<int>& nums, int k) {
		int sum = 0;
		unordered_map<int, int> s_map;
		s_map[0] = 0;
		for (int i = 0; i < nums.size(); ++i) {
			sum += nums[i];
			sum %= k;
			if (s_map.find(sum) != s_map.end()) {
				if (((i + 1) - s_map[sum]) > 1) return true;
			} else s_map[sum] = i + 1;
		}
		return false;
	}
};