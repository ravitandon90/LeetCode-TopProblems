#include<vector>

using namespace std;

class InsertSort {
public:
	void sort(vector<int>& nums) {
		for (int i = 1; i < nums.size(); ++i) {
			int j = i;
			while (j > 0 && isDescending(nums, j - 1, j)) {
				swap(nums, j - 1 , j);
				--j;
			}
		}
	}

private:
	bool isDescending(const vector<int>& nums, int i, int j) {
		return nums.at(i) > nums.at(j);
	}

	void swap(vector<int>& nums, int i, int j) {
		int tmp = nums.at(i);
		nums[i] = nums[j];
		nums[j] = tmp;
	}
};