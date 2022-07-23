#include <unordered_map>

using namespace std;

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


// Problem: https://leetcode.com/problems/lru-cache/

struct Node {
	Node(): right(nullptr), left(nullptr), key(-1), value(-1) {}

	Node* right;
	Node* left;
	int key;
	int value;
};

class LRUCache {
public:    
    LRUCache(int capacity) {
		max_size = capacity;
		head = new Node();
		tail = new Node();
		head->right = tail;
		tail->left = head;
	}

	void put(int key, int value) {
		Node* node_value = nullptr;
		// Step-I: Check if the key exists in the map.
		if (node_map.find(key) != node_map.end()) {
			// Step-II: If exists, update node; push to front.
			node_value = node_map[key];
			node_value->value = value;
            node_map[key] = node_value;
            removeNode(node_value);		
		} else {
			// Step-III: If not exists, create node, push to front.
			node_value = new Node();
			node_value->key = key;
			node_value->value = value;
			node_map[key] = node_value;
		}

		insertNodeFront(node_value);
		// Step-IV: Check if need to evict. If yes, delete the last node.
		if (node_map.size() > max_size) {
			Node* delete_node = deleteFromBack();
			node_map.erase(delete_node->key);
			delete delete_node;
		}
	}
	
	int get(int key) {
		// Step-I: Check if the key exists in the map.
		if (node_map.find(key) == node_map.end()) return -1;
		// Step-II: If exists, push to front, return value;
		Node* node_value = node_map[key];
		removeNode(node_value);
		insertNodeFront(node_value);
		return node_value->value;
	}
    
private:
 	void removeNode(Node* node) {
 		Node* p = node->left;
 		Node* n = node->right;
 		p->right = n;
 		n->left = p;
 		node->left = nullptr;
 		node->right = nullptr;
 	}
 	
 	void insertNodeFront(Node* node) {
 		Node* tmp = head->right;
 		head->right = node;
 		node->right = tmp;
 		node->left = head;
 		tmp->left = node;
 	}

 	Node* deleteFromBack() {
 		Node* back = tail->left;
 		tail->left = back->left;
 		tail->left->right = tail;
 		back->right = nullptr;
 		back->left = nullptr;
 		return back;
 	}

 	unordered_map<int, Node*> node_map;
 	Node* head;
 	Node* tail;
 	int max_size;
};

