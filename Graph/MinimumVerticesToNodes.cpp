// Problem: https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/

#include <vector>

using namespace std;

class MinimumVerticesToNodes {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> incoming;
        vector<int> result;
        incoming.resize(n, 0);
        int count = 0;
        for (int i = 0; i < edges.size(); ++i) incoming[edges[i][1]]++;
        for (int i = 0; i < n; ++i) { 
            if (incoming[i] == 0) {
                result.push_back(i);
            }
        }
        return result;
    }
};