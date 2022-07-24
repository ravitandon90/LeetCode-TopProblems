// Problem: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

#include<vector>

using namespace std;

class FindMinRotatedSortedArray {
public:
	int findMin(vector<int>& nums) {
		return findMinInt(nums, 0, nums.size() - 1);
	}

private:
	int findMinInt(const vector<int>& nums, int s, int e) {
		if (s == e) return nums.at(s);
		if ((s + 1) == e) return std::min(nums.at(s), nums.at(e));
		int mid = (s + e) / 2;
		if (nums.at(mid) < nums.at(e)) return findMinInt(nums, s, mid);
		return findMinInt(nums, mid, e);
	}
};