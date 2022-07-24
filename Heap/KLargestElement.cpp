// Problem: https://leetcode.com/problems/kth-largest-element-in-an-array/

#include<priority_queue>
#include<vector>

using namespace std;

class KLargestElement {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for (int i = 0; i < nums.size(); ++i) pq.push(nums[i]);
        for (int i = 1; i < k; ++i) pq.pop();
        return pq.top();
    }
};