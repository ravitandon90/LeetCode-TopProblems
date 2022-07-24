// Problem: https://leetcode.com/problems/implement-queue-using-stacks/

#include <stack>

using namespace std;

/**
 * Your QueueWithStacks object will be instantiated and called as such:
 * QueueWithStacks* obj = new QueueWithStacks();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
class QueueWithStacks {
public:
    /** Initialize your data structure here. */
    QueueWithStacks() {}
    
    /** Push element x to the back of queue. */
    void push(int x) { st_1_.push(x); }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int val;
        while (st_1_.size() > 1) {
            st_2_.push(st_1_.top());
            st_1_.pop();
        }
        val = st_1_.top();
        st_1_.pop();
        while (st_2_.size() > 0) {
            push(st_2_.top());
            st_2_.pop();
        }
        return val;
    }
    
    /** Get the front element. */
    int peek() {
        int val;
        while (st_1_.size() > 0) {            
            st_2_.push(st_1_.top());
            st_1_.pop();
        }        
        val = st_2_.top();        
        while (st_2_.size() > 0) {
            push(st_2_.top());
            st_2_.pop();
        }
        return val;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() { return st_1_.empty(); }
    
 private:
    stack<int> st_1_;
    stack<int> st_2_;
};