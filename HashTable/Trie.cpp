/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

#include<vector>

struct Node {
    Node() {
        children.resize(26, nullptr);
    }
    vector<Node*> children;
    bool wordEnds = false;
};

class Trie {
public:
    Trie() {
        root = new Node();        
    }
    
    void insert(string word) {
        if (word.size() == 0) return;
        int index = 0;
        Node* curr = root;        
        while (true) {
            const char ch = word.at(index);
            Node* child = curr->children.at(ch - 'a');
            if (child == nullptr) {
                child = new Node();
                curr->children[ch - 'a'] = child;
            }
            curr = child;
            ++index;
            if (index == word.size()) {
                child->wordEnds = true;
                break;
            }
        }
    }
    
    bool search(string word) {
        if (word.size() == 0) return true;
        int index = 0;
        Node* curr = root;
        while (true) {
            const char ch = word.at(index);
            Node* child = curr->children.at(ch - 'a');
            if (child == nullptr) return false;
            curr = child;
            ++index;
            if (index == word.size()) {
                return child->wordEnds;                
            }
        }
        return true;
    }
    
    bool startsWith(string prefix) {
        const string& word = prefix;
        if (word.size() == 0) return true;
        int index = 0;
        Node* curr = root;
        while (true) {
            const char ch = word.at(index);
            Node* child = curr->children.at(ch - 'a');
            if (child == nullptr) return false;
            curr = child;
            ++index;
            if (index == word.size()) {
                return true;                
            }
        }
        return true;
    }
    
 private:
    Node* root;
};