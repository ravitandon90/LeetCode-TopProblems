// Problem: https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

#include<priority_queue>
#include<vector>

using namespace std;

class KSmallestElementMatrix {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int, vector<int>, std::greater<int>> pq;        
        for (int i = 0; i < min(k+1, (int)matrix.size()); ++i) {
            vector<int> row = matrix[i];
            for (int j = 0; j < min(k +1, (int)row.size()); ++j) {
                pq.push(row[j]);
            }
        }
        for (int i = 1; i < k; ++i) pq.pop();                
        return pq.top();
    }
};