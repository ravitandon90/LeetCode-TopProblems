#include<unordered_map>
#include<unordered_set>
#include<vector>

using namespace std;

class ConnectedComponents {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        // Step-I: Build connected graph.
        unordered_map<int, vector<int>> edges_map;
        for (int i = 0; i < n; ++i) edges_map[i].push_back(i);
        for (int i = 0; i < edges.size(); ++i) {
            edges_map[edges.at(i)[0]].push_back(edges.at(i)[1]);
            edges_map[edges.at(i)[1]].push_back(edges.at(i)[0]);
        }
        
        // Step-II: For each node, find the min(nodeId) in the connected graph
        unordered_map<int, vector<int>>::iterator it;
        unordered_set<int> connected_components;
        unordered_set<int> seen;
        for (it = edges_map.begin(); it != edges_map.end(); ++it) {            
            int componentId = it->first;
            if (seen.find(componentId) != seen.end()) continue;
            findMinDFS(edges_map, componentId, componentId, seen);
            connected_components.insert(componentId);
        }
        return connected_components.size();
    }
    
private:
    void findMinDFS(const unordered_map<int, vector<int>>& edges_map, 
               int& componentId, int curr_vertex, unordered_set<int>& seen) {
        // Base Case: We have seen @curr_vertex.
        if (seen.find(curr_vertex) != seen.end()) return;
        seen.insert(curr_vertex);
        if (componentId > curr_vertex) componentId = curr_vertex;        
        // Case-II: @curr_vertex has edges. Iterate through all the edges.
        const vector<int>& children = edges_map.at(curr_vertex);
        for (const int child : children) {
            findMinDFS(edges_map, componentId, child, seen);
        }
    }
};