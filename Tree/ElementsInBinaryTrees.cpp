// Problem: https://leetcode.com/problems/all-elements-in-two-binary-search-trees/

#include <algorithm>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class ElementsInBinaryTrees {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> result;
        parse(root1, result);
        parse(root2, result);
        sort(result.begin(), result.end());
        return result;
    }

    void parse(TreeNode* root, vector<int>& result) {
        if (root == nullptr) return;
        result.push_back(root->val);
        parse(root->left, result);
        parse(root->right, result);
    }
};