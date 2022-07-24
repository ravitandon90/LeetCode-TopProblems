// Problem: https://leetcode.com/problems/partition-array-for-maximum-sum/

#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class PartitionArrayMaximumSum {
public:
	int maxSumAfterPartitioning(vector<int>& arr, int k) {
		unordered_map<int, int> memo;
		return maxSumAfterPartitioningInt(arr, k, 0, memo);
	}

private:
	int maxSumAfterPartitioningInt(const vector<int>& arr, int k,
	                               int start, unordered_map<int, int>& memo) {
		// No more partitions can be created.
		if (start >= arr.size()) return 0;

		// If we have seen this subarray before, return from the memory.
		if (memo.find(start) != memo.end()) return memo[start];

		// Getting the maximum sum for the current partition.
		int max_sum = 0;
		int part_sum = 0;
		for (int i = 1; i <= k; ++i) {
			part_sum = getPartSum(arr, start, i) + maxSumAfterPartitioningInt(arr, k, start + i, memo);
			max_sum = std::max(max_sum, part_sum);
		}
		memo[start] = max_sum;
		return max_sum;
	}

	int getPartSum(const vector<int>& arr, int start, int size) {
		int num_elements = 0;
		int max_element = 0;
		for (int i = 0; i < size; ++i) {
			int curr_index = i + start;
			if (curr_index > (arr.size() - 1)) break;
			max_element = std::max(max_element, arr.at(curr_index));
			++num_elements;
		}
		return max_element * num_elements;
	}
};