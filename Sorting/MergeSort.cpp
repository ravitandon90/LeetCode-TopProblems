#include <vector>

using namespace std;

class MergeSort {
public:
	void sort(vector<int>& nums) {
		mSort(nums, 0, nums.size() - 1);
	}

private:
	void mSort(vector<int>& nums, int low, int high) {
		if (high <= low) return;
		int mid = (high + low) / 2;
		mSort(nums, low, mid);
		mSort(nums, mid + 1, high);
		merge(nums, low, mid, mid + 1, high);
	}

	void merge(vector<int>& nums, int s1, int e1, int s2, int e2) {
		vector<int> tmp1;
		vector<int> tmp2;
		for (int idx = s1; idx <= e1; ++idx) tmp1.push_back(nums[idx]);
		for (int idx = s2; idx <= e2; ++idx) tmp2.push_back(nums[idx]);
		int idx1 = 0; int idx2 = 0; int curr = s1;
		while (idx1 < tmp1.size() && idx2 < tmp2.size()) {
			if (tmp1[idx1] < tmp2[idx2]) {
				nums[curr] = tmp1[idx1];
				++idx1;
				++curr;
			} else {
				nums[curr] = tmp2[idx2];
				++idx2;
				++curr;
			}
		}
		while (idx1 < tmp1.size()) {
			nums[curr] = tmp1[idx1];
			++idx1;
			++curr;
		}
		while (idx2 < tmp2.size()) {
			nums[curr] = tmp2[idx2];
			++idx2;
			++curr;
		}
	}

	void swap(vector<int>& nums, int i, int j) {
		int tmp = nums.at(i);
		nums[i] = nums[j];
		nums[j] = tmp;
	}
};