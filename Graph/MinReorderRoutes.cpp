// Problem: https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class MinReorderRoutes {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        int count =  0;
        unordered_set<int> seen;
        vector<vector<int>> adjacency_list;
        adjacency_list.resize(n, {});
        // false: outgoing, true: incoming.
        unordered_map<string, bool> direction;
        for (int i = 0; i < connections.size(); ++i) {
            adjacency_list[connections[i][0]].push_back(connections[i][1]);
            adjacency_list[connections[i][1]].push_back(connections[i][0]);
            direction[toString(connections[i][0], connections[i][1])] = false;
            direction[toString(connections[i][1], connections[i][0])] = true;
        }
        dfs(0, count, seen, adjacency_list, direction);
        return count;
    }

    void dfs(int curr, int& count,
             unordered_set<int>& seen,
             const vector<vector<int>>& adjacency_list,
             const unordered_map<string, bool>& direction) {
        if (seen.find(curr) != seen.end()) return;
        seen.insert(curr);
        vector<int> neighbors = adjacency_list[curr];
        for (int neighbor : neighbors) {
            if (seen.find(neighbor) != seen.end()) continue;
            string key = toString(curr, neighbor);
            if (direction.at(key) == false) ++count;
            dfs(neighbor, count, seen, adjacency_list, direction);
        }
    }

    string toString(int x, int y) {
        return to_string(x) + std::string(",") + to_string(y);
    }
};