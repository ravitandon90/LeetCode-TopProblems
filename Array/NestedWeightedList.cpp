// Problem: https://leetcode.com/problems/nested-list-weight-sum/

#include <vector>

using namespace std;

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedWeightedList {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        int sum = 0;
        parse(nestedList, 0, sum);
        return sum;
    }
    
    void parse(const vector<NestedInteger>& nestedList, int index, int& sum) {
        for (int i = 0; i < nestedList.size(); ++i) parse(nestedList[i], index + 1, sum);
    }
    
    void parse(const NestedInteger& nestedInteger, int index, int& sum) {
        if (nestedInteger.isInteger()) sum += nestedInteger.getInteger() * index;                    
        else parse(nestedInteger.getList(), index, sum);
    }
};