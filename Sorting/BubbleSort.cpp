#include<vector>

using namespace std;

class HeapSort {
public:
	void sort(vector<int>& nums) {
		for (int i = 0; i < nums.size(); ++i) {
			for (int j = 0; j < nums.size() - i - 1; ++j) {
				if (nums[j] > nums[j + 1]) swap(nums, j, j + 1);
			}
		}
	}

private:
	void swap(vector<int>& nums, int i, int j) {
		int tmp = nums.at(i);
		nums[i] = nums[j];
		nums[j] = tmp;
	}

};