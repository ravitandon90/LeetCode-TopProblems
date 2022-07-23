#include<unordered_map>

using namespace std;

// Definition for a Node.
struct Node {
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class CloneGraph {
public:
    Node* cloneGraph(Node* node) {
        // Base case: node is nullptr.
        if (node == nullptr) return nullptr;
        
        // Keep an unordered_set.
        unordered_map<int, Node*> seen;
        
        // Implement DFS
        return cloneGraphDFS(node, seen);
    }
    
    Node* cloneGraphDFS(Node* node, unordered_map<int, Node*>& seen) {        
        // Base Case
        if (node == nullptr) return nullptr;
        
        // If node is already seen.
        if (seen.find(node->val) != seen.end()) return seen[node->val];
        
        // Building a new node.
        Node* newNode = new Node(node->val);
        seen[newNode->val] = newNode;
        
        // If node is not seen.
        for (int i = 0; i < node->neighbors.size(); ++i) {
            newNode->neighbors.push_back(cloneGraphDFS(node->neighbors.at(i), seen));
        }
        
        // Return the newly created node.
        return newNode;        
    }
};