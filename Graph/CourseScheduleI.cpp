#include <unordered_map>
#include <vector>

using namespace std;

class CourseSchedule {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Base Case: Only 1 course exists.
        if (numCourses < 2) return true;
        
        // Step-I: Build dependency graph.
        unordered_map<int, vector<int>> dependency_graph;                
        for (int i = 0; i < prerequisites.size(); ++i) {
            dependency_graph[prerequisites.at(i)[0]].push_back(prerequisites.at(i)[1]);
        }
        
        // Step-II: Verify dependency graph.
        unordered_map<int, vector<int>>::iterator it;
        unordered_set<int> checked;
        for (it = dependency_graph.begin(); it != dependency_graph.end(); ++it) {
            unordered_set<int> seen;
            if (not dfs(dependency_graph, it->first, seen, checked)) return false;
            checked.insert(it->first);
        }
        // No cycles found, we are good.
        return true;
    }
    
 private:
    bool dfs(const unordered_map<int, vector<int>>& dependency_graph, 
             int parent, unordered_set<int>& seen, unordered_set<int>& checked) {
        // Base Case: If we have seen this parent, then there is a cycle.
        if (seen.find(parent) != seen.end()) return false;        
        if (checked.find(parent) != checked.end()) return true;
        
        // Go through all the children of the parent.
        // Case-I: Parent has no dependencies.
        if (dependency_graph.find(parent) == dependency_graph.end()) return true;
        
        seen.insert(parent);
        // Case-II: Parent has dependent children.
        const vector<int>& children = dependency_graph.at(parent);
        for (const int child : children) {
            if (not dfs(dependency_graph, child, seen, checked)) return false;
        }
        seen.erase(parent);
        checked.insert(parent);
        
        // No child is dependent on the parent.
        return true;
    }
    
};