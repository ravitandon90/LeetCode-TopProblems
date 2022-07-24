// Problem: https://leetcode.com/problems/dot-product-of-two-sparse-vectors/

#include<vector>

using namespace std;

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);
class SparseVector {
public:
    SparseVector(vector<int> &nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) _vec_map[i] = nums[i];
        }
    }

    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        unordered_map<int, int>::iterator it1;
        unordered_map<int, int>::iterator it2;
        unordered_set<int> seen;
        return getSum(_vec_map, vec._vec_map, seen) + getSum(vec._vec_map, _vec_map, seen);
    }

private:
    int getSum(unordered_map<int, int>& m1, unordered_map<int, int>&m2, unordered_set<int>& seen) {
        unordered_map<int, int>::iterator it1;
        unordered_map<int, int>::iterator it2;
        int sum = 0;
        for (it1 = m1.begin(); it1 != m1.end(); ++it1) {
            if (seen.find(it1->first) != seen.end()) continue;
            it2 = m2.find(it1->first);
            if (it2 != m2.end()) {
                sum +=  it1->second  * it2->second;
            }
            seen.insert(it1->first);
        }
        return sum;
    }

    unordered_map<int, int> _vec_map;
};