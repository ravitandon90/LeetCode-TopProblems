// Problem: https://leetcode.com/problems/max-stack/

#include <bits/stdc++.h>
#include <stack>

using namespace std;

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */
class MaxStack {
public:
    /** initialize your data structure here. */
    MaxStack(): curr_max_(INT_MIN) {}

    void push(int x) {
        st_.push(x);
        curr_max_ = max(curr_max_, x);
        max_st_.push(curr_max_);
    }

    int pop() {
        int val = st_.top(); st_.pop();
        max_st_.pop();
        if (max_st_.empty()) curr_max_ = INT_MIN;
        else curr_max_ = max_st_.top();
        return val;
    }

    int top() { return st_.top(); }

    int peekMax() { return curr_max_; }

    int popMax() {
        vector<int> vals;
        int retVal = curr_max_;
        while (st_.size() > 0 && curr_max_ != st_.top()) {
            vals.push_back(st_.top());
            st_.pop(); max_st_.pop();
        }
        st_.pop(); max_st_.pop();
        if (max_st_.empty()) curr_max_ = INT_MIN;
        else curr_max_ = max_st_.top();
        for (int i = vals.size() - 1; i >= 0; --i) push(vals[i]);
        return retVal;
    }

private:
    stack<int> st_;
    stack<int> max_st_;
    int curr_max_;
};