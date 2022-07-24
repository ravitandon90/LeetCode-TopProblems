// Problem: https://leetcode.com/problems/all-paths-from-source-lead-to-destination/

#include <vector>

using namespace std;

class PathFinder {
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges,
                            int source, int destination) {
        vector<vector<int>> adjaceny_list;
        adjaceny_list.resize(n, {});
        for (int i = 0; i < edges.size(); ++i) adjaceny_list[edges[i][0]].push_back(edges[i][1]);
        // 0: Unprocessed
        // 1: In-Process
        // 2: Processed
        vector<int> node_state;
        node_state.resize(n, 0);
        return findPath(source, destination, node_state, adjaceny_list);
    }

    bool findPath(int src, int destination,
                  vector<int>& node_state,
                  const vector<vector<int>>& adjaceny_list) {
        bool found = src == destination;
        int src_state = node_state[src];
        // A loop exists given this node was still being processed.
        if (src_state == 1) return false;
        if (src_state == 2) return true;
        // We are now processing this node.
        node_state[src] = 1;
        vector<int> children = adjaceny_list[src];
        for (int i = 0; i < children.size(); ++i) {
            int child = children[i];
            found = findPath(child, destination, node_state, adjaceny_list);
            if (not found) return false;
        }
        // After processing the node.
        node_state[src] = 2;
        return found;
    }
};