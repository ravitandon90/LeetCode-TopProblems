// Problem: https://leetcode.com/problems/two-sum-iii-data-structure-design/

#include <unordered_map>
#include <vector>

using namespace	std;

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */
class TwoSumStream {
public:
	/** Initialize your data structure here. */
	TwoSum() {}

	/** Add the number to an internal data structure.. */
	void add(int number) { nums_[number]++; }

	/** Find if there exists any pair of numbers which sum is equal to the value. */
	bool find(int value) {
		unordered_map<long int, int>::iterator it;
		for (it = nums_.begin(); it != nums_.end(); ++it) {
			long int curr = it->first;
			long int complement = value - curr;
			if (curr == complement) {
				if (it->second > 1) return true;
			} else {
				if (nums_.find(complement) != nums_.end()) return true;
			}
		}
		return false;
	}

private:
	unordered_map<long int, int> nums_;
};
