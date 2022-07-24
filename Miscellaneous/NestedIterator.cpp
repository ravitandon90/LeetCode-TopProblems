// Problem: https://leetcode.com/problems/flatten-nested-list-iterator/

#include <vector>

using namespace std;

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        flatten(nestedList);
        curr_ = -1;
    }

    int next() {
        curr_++;
        return nums_.at(curr_);
    }

    bool hasNext() { return curr_ < ((int)nums_.size() - 1); }

private:
    void flatten(const vector<NestedInteger> &nestedList) {
        for (int i = 0; i < nestedList.size(); ++i) {
            if (not nestedList[i].isInteger()) {
                flatten(nestedList[i].getList());
            } else {
                nums_.push_back(nestedList[i].getInteger());
            }
        }
    }

    int curr_;
    vector<int> nums_;
};
