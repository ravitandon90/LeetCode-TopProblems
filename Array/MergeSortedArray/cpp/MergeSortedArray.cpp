// Problem: https://leetcode.com/problems/merge-sorted-array/

#include<vector>

using namespace std;

class MergeSortedArray {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		vector<int> numsCopy;
		int i1 = 0;
		int i2 = 0;
		while (i1 < m && i2 < n) {
			if (nums1[i1] <= nums2[i2]) { numsCopy.push_back(nums1[i1]); ++i1; }
			else { numsCopy.push_back(nums2[i2]); ++i2; }
		}
		while (i1 < m)  {
			numsCopy.push_back(nums1[i1]); ++i1;
		}
		while (i2 < n)  {
			numsCopy.push_back(nums2[i2]); ++i2;
		}
		nums1 = numsCopy;
	}
};