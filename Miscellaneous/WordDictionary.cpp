// Problem: https://leetcode.com/problems/design-add-and-search-words-data-structure/

#include <string>

using namespace std;

struct Node {
    unordered_map<char, Node*> node_map;
    bool is_leaf = false;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() { this->_head = new Node(); }

    void addWord(const string& word) {
        Node* curr = this->_head;
        Node* prev = curr;
        int index = 0;
        // Step-I: Search
        for (; index < word.size(); ++index) {
            char curr_ch = word[index];
            if (curr->node_map.find(curr_ch) == curr->node_map.end()) break;
            prev = curr;
            curr = curr->node_map[curr_ch];
            if (curr == nullptr) break;
        }
        if (index == word.size()) curr->is_leaf = true;
        if (curr == nullptr) curr = prev;

        // Step-II: Insert.
        for (; index < word.size(); ++index) {
            char curr_ch = word[index];
            curr->node_map[curr_ch] = new Node();
            // This is the last character to be inserted.
            // Therefore, the new node will be a leaf.
            if (index == (word.size() - 1)) {
                curr->node_map[curr_ch]->is_leaf = true;
            } else {
                curr = curr->node_map[curr_ch];
            }
        }
    }

    bool search(const string& word) { return searchInt(this->_head, word); }

private:
    bool searchInt(Node* node, string word) {
        Node* curr = node;
        for (int index = 0; index < word.size(); ++index) {
            char curr_ch = word[index];
            if (curr_ch == '.') {
                for (auto it = curr->node_map.begin(); it != curr->node_map.end(); ++it) {
                    string rem_word = "";
                    if (index < (word.size() - 1)) {
                        rem_word = word.substr(index + 1);
                    }
                    if (searchInt(it->second, rem_word)) return true;
                }
                return false;
            } else {
                if (curr->node_map.find(curr_ch) == curr->node_map.end()) return false;
                curr = curr->node_map[curr_ch];
                if (curr == nullptr) return false;
            }
        }
        return curr != nullptr && curr->is_leaf;
    }

    Node* _head = nullptr;
};