#include<vector>

using namespace std;

class HeapSort {
public:
    void sort(vector<int>& nums) {
        vector<int> result;
        int size = nums.size();
        for (int i = size / 2 - 1; i >= 0; --i) {
            heapify(nums, nums.size(), i);
        }
        for (int i = size - 1; i >= 0; --i) {
            swap(nums, i, 0);
            heapify(nums, i, 0);
        }
    }

private:
    void heapify(vector<int>& nums, int size, int index) {
        int l = 2 * index + 1;
        int r = 2 * index + 2;
        int largest = index;
        if (l < size && nums[largest] < nums[l]) largest = l;
        if (r < size && nums[largest] < nums[r]) largest = r;
        if (largest != index) {
            swap(nums, largest, index);
            heapify(nums, size, largest);
        }
    }
    void swap(vector<int>& nums, int i, int j) {
        int tmp = nums.at(i);
        nums[i] = nums[j];
        nums[j] = tmp;
    }

};