// Problem: https://leetcode.com/problems/maximum-score-from-removing-stones/

#include<priority_queue>
#include<vector>

using namespace std;

class MaximumScore {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int, vector<int>> pq;
        pq.push(a); pq.push(b); pq.push(c);
        int output = 0;
        while (pq.size() > 1) {
            int v1 = pq.top(); pq.pop();
            int v2 = pq.top(); pq.pop();
            ++output; --v1; --v2;
            if (v1 > 0) pq.push(v1);
            if (v2 > 0) pq.push(v2);
        }
        return output;
    }
};