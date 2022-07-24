// Problem: https://leetcode.com/problems/find-if-path-exists-in-graph/

#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class FindIfPathExists {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        int MAX_NODES = 2 * 100000;
        queue<int> nq;
        vector<vector<int>> node_map;
        node_map.resize(MAX_NODES + 1, {});
        unordered_set<int> seen;
        for (int i = 0; i < edges.size(); ++i) { 
            node_map[edges[i][0]].push_back(edges[i][1]);
            node_map[edges[i][1]].push_back(edges[i][0]);
        }
        nq.push(start);
        while (not nq.empty()) {
            int source_node_id = nq.front(); nq.pop();
            if (source_node_id == end) return true;
            for (int i = 0; i < node_map[source_node_id].size(); ++i) {
                int dest_node_id = node_map[source_node_id][i];
                if (seen.find(dest_node_id) != seen.end()) continue;
                nq.push(dest_node_id);
            }
            seen.insert(source_node_id);
        }
        return false;
    }
};