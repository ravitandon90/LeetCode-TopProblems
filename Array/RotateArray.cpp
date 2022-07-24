// Problem: https://leetcode.com/problems/rotate-array/

#include<vector>

using namespace std;

class RotateArray {
public:
	void rotate(vector<int>& nums, int k) {
		if (k == 0) return;
		int buffer[k];
		int max_size = nums.size();
		for (int i = 0; i < k; ++i) buffer[i] = 0;
		int num_changes = 0;
		int curr_index = 0;
		swapK(buffer, nums, curr_index, k);
		curr_index += k;
		while (num_changes < max_size) {
			swapK(buffer, nums, curr_index, min(k, max_size - num_changes));
			num_changes += k;
			curr_index += k;
		}
	}

private:
	void swap(int* a, int * b) {
		int temp = *b;
		*b = *a;
		*a = temp;
	}

	void swapK(int* a, vector<int>& b, int s, int k) {
		int max_size = b.size();
		for (int i = 0; i < k; ++i) {
			swap(a + i, &(b[(i + s) % max_size]));
		}
	}
};