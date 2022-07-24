// Problem: https://leetcode.com/problems/find-center-of-star-graph/

#include <vector>

using namespace std;

class FindCenterOfGraph {
public:
    int findCenter(vector<vector<int>>& edges) {
        int MAX_NODES = 100000;
        vector<int> edge_size;
        edge_size.resize(MAX_NODES + 1, 0);
        int max_edge = INT_MIN;
        int max_edge_index = -1;
        for (int i = 0; i < edges.size(); i++) {
            edge_size[edges[i][0]]++;
            edge_size[edges[i][1]]++;
            if (max_edge < edge_size[edges[i][0]]) {
                max_edge = edge_size[edges[i][0]];
                max_edge_index = edges[i][0];
            }
            if (max_edge < edge_size[edges[i][1]]) {
                max_edge = edge_size[edges[i][1]];
                max_edge_index = edges[i][1];
            }
        }
        return max_edge_index;
    }
};