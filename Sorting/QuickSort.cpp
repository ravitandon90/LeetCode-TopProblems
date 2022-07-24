#include<vector>

using namespace std;

class QuickSort {
public:
	void sort(vector<int>& nums) {
		qSort(nums, 0, nums.size() - 1);
	}

private:
	void qSort(vector<int>& nums, int low, int high) {
		if (low >= high) return;
		int p = partition(nums, low, high);
		qSort(nums, low, p - 1);
		qSort(nums, p + 1, high);
	}

	int partition(vector<int>& nums, int low, int high) {
		int pivot = nums[high];
		int i = low - 1;
		for (int j = low; j < high; ++j) {
			if (nums[j] < pivot) {
				++i;
				swap(nums, j, i);
			}
		}
		swap(nums, i + 1, high);
		return (i + 1);
	}

	void swap(vector<int>& nums, int i, int j) {
		int tmp = nums.at(i);
		nums[i] = nums[j];
		nums[j] = tmp;
	}
};