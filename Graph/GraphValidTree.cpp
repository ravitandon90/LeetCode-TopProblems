#include<vector>

using namespace std;

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // Base Case.
        if (edges.size() != (n - 1)) return false;

        // Step-1: Build adjacency-list.
        vector<int> emptyVec;
        vector<vector<int>> adjacencyList(n, emptyVec);
        for (const auto& edge : edges) {
            adjacencyList[edge[0]].push_back(edge[1]);
            adjacencyList[edge[1]].push_back(edge[0]);
        }

        // Step-II: DFS.
        unordered_set<int> seen;
        return dfs(0, -1, adjacencyList, seen) && seen.size() == n;
    }

private:
    bool dfs(int node, int parent,
             const vector<vector<int>>& adjacencyList, unordered_set<int>& seen) {
        if (seen.find(node) != seen.end()) return false;
        seen.insert(node);

        const vector<int>& neighbors = adjacencyList.at(node);
        for (const int neighbor : neighbors) {
            if (parent != neighbor) {
                if (not dfs(neighbor, node, adjacencyList, seen)) {
                    return false;
                }
            }
        }
        return true;
    }
};