#include<algorithm>
#include<vector>
#include<priority_queue>

using namespace std;

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

class MedianFinder {
public:
    MedianFinder() {}
    void addNum(int num) {
        // Step-I: Add to Max-Heap.
        max_heap.push(num);

        // Step-II: Balance the trees.
        min_heap.push(max_heap.top());
        max_heap.pop();

        // Step-III: Keep the max-heap size larger.
        if (max_heap.size() < min_heap.size()) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }

    }

    double findMedian() {
        if (max_heap.size() > min_heap.size()) return max_heap.top();
        return (0.5) * (double)(min_heap.top() + max_heap.top());
    }

private:
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, std::greater<int>> min_heap;
};