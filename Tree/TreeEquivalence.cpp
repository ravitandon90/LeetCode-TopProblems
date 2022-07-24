#include<vector>
#include<unordered_map>

using namespace std;

// Definition for a binary tree node.
struct Node {
    char val;
    Node *left;
    Node *right;
    Node() : val(' '), left(nullptr), right(nullptr) {}
    Node(char x) : val(x), left(nullptr), right(nullptr) {}
    Node(char x, Node *left, Node *right) : val(x), left(left), right(right) {}
};

class TreeEquivalence {
public:
    bool checkEquivalence(Node* root1, Node* root2) {
        unordered_map<char, int> charCount1, charCount2;
        parseTree (root1, &charCount1);
        parseTree (root2, &charCount2);
        return compare(charCount1, charCount2) && compare(charCount2, charCount1);
    }

private:
    bool compare(unordered_map<char, int>& m1,  unordered_map<char, int>& m2) {
        unordered_map<char, int>::iterator it1, it2;
        for (it1 = m1.begin(); it1 != m1.end(); ++it1) {
            it2 = m2.find(it1->first);
            if (it2 == m2.end()) return false;
            if (it2->second != it1->second) return false;
        }
        return true;
    }

    void parseTree(Node* root, std::unordered_map<char, int>* charCount) {
        if (root == nullptr) return;
        unordered_map<char, int>::iterator it;
        (*charCount)[root->val]++;
        parseTree(root->left, charCount);
        parseTree(root->right, charCount);
    }
};