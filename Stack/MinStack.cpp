// Problem: https://leetcode.com/problems/min-stack/

#include <stack>

using namespace std;

struct Node {
    Node(int v, int mv) : _val(v), _min_val(mv) {}
    int _val;
    int _min_val;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {}

    void push(int val) {
        int min_val = val;
        if (not this->_st.empty()) {
            min_val = min(val, this->_st.top()._min_val);
        }
        this->_st.push(Node(val, min_val));
    }

    void pop() { this->_st.pop(); }
    int top() { return this->_st.top()._val; }
    int getMin() { return this->_st.top()._min_val; }

private:
    stack<Node> _st;
};