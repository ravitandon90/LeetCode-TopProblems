// Problem: https://leetcode.com/problems/kth-largest-element-in-a-stream/

#include <algorithm>
#include <priority_queue>
#include <vector>

using namespace std;

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
class KthLargestFromStream {
public:
    KthLargest(int k, vector<int>& nums) {
        max_size_ = k;
        for (int i = 0; i < nums.size(); ++i) {
            pq_.push(nums[i]);
            if (pq_.size() > k) pq_.pop();
        }
    }

    int add(int val) {
        pq_.push(val);
        if (pq_.size() > max_size_) pq_.pop();
        return pq_.top();
    }

private:
    priority_queue<int, vector<int>, std::greater<int>> pq_;
    int max_size_;
};
