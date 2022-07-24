// Problem: https://leetcode.com/problems/max-consecutive-ones/

#include <vector>

using namespace std;

class ConsecutiveOnes {
public:
	int findMaxConsecutiveOnes(vector<int>& nums) {
		int max_len = 0, curr_len = 0;
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] == 0) curr_len = 0;
			else {
				curr_len++;
				max_len = max(curr_len, max_len);
			}
		}
		max_len = max(curr_len, max_len);
		return max_len;
	}
};