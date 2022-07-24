// Problem: https://leetcode.com/problems/insert-delete-getrandom-o1/

#include <unordered_map>
#include <vector>

using namespace std;

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {}
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {    
        if (nums_map_.find(val) != nums_map_.end()) return false;
        nums_ar_.push_back(val);
        nums_map_[val] = nums_ar_.size() - 1;
        return true;                
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (nums_map_.find(val) == nums_map_.end()) return false;
        int idx = nums_map_.at(val);
        swap(nums_ar_, idx, nums_ar_.size() - 1);
        nums_ar_.pop_back();
        nums_map_[nums_ar_[idx]] = idx;
        nums_map_.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        double frac = (double)rand() / (double)RAND_MAX;
        int idx = frac * (nums_ar_.size());
        if (idx == nums_ar_.size()) return getRandom();
        return nums_ar_.at(idx);
    }
    
private:
    void swap(vector<int>& ar, int i, int j) {
        if (i == j) return;
        int tmp = ar[i];
        ar[i] = ar[j];
        ar[j] = tmp;
    }
    
    unordered_map<int, int> nums_map_;
    vector<int> nums_ar_;
};
