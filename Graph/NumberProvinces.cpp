// Problem: https://leetcode.com/problems/number-of-provinces/

#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

class NumberProvinces {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int num_nodes = isConnected.size();
        unordered_set<int> seen;
        int num_provinces = 0;
        for (int i = 0; i < num_nodes; ++i) {
            if (seen.find(i) != seen.end()) continue;
            ++num_provinces;
            queue<int> nodes;
            nodes.push(i);
            while (not nodes.empty()) {
                int curr_node = nodes.front(); nodes.pop();
                seen.insert(curr_node);
                for (int j = 0; j < num_nodes; ++j) {
                    if (isConnected[curr_node][j]) {
                        if (seen.find(j) == seen.end()) {
                            nodes.push(j);
                        }
                    }
                }
            }
        }
        return num_provinces;
    }
};