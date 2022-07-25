// Problem: https://leetcode.com/problems/all-paths-from-source-to-target/

#include <unordered_set>
#include <vector>

using namespace std;

class PathsFromSourceToTarget {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths;
        unordered_set<int> seen;
        vector<int> path;
        dfs(graph, seen, paths, path, 0 /* current */, graph.size() - 1 /* target */);
        return paths;
    }

    void dfs(const vector<vector<int>>& graph, unordered_set<int>& seen,
             vector<vector<int>>& paths, vector<int>& path, int current, int target) {
        if (seen.find(current) != seen.end()) return;
        if (current == target) {
            path.push_back(current);
            paths.push_back(path);
            path.pop_back();
            return;
        }
        path.push_back(current);
        seen.insert(current);
        for (int i = 0; i < graph[current].size(); ++i) {
            int next = graph[current][i];
            dfs(graph, seen, paths, path, next, target);
        }
        seen.erase(current);
        path.pop_back();
    }
};