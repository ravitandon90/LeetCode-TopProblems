// Link to problem: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

#include<iostream>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class LowestCommonAncestor {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base Case: Root is nullptr.
        if (root == nullptr) return root;

        // Case I: Root is LCA.

        // Case I(a): None of p & q is root.
        if (findNode(root->left, p) && findNode(root->right, q) ||
                findNode(root->right, p) && findNode(root->left, q)) {
            return root;
        }

        // Case II(a): One of p & q is root.
        if ((p == root) || (q == root)) {
            return root;
        }

        // Case II: LCA is in the left subtree.
        TreeNode* val = lowestCommonAncestor(root->left, p, q);
        if (val) return val;

        return lowestCommonAncestor(root->right, p, q);
    }

private:
    TreeNode* findNode(TreeNode* root, TreeNode* target) {
        // Base Cases: Root is the target, or Root is nullptr.
        if (root == nullptr || root == target) return root;

        // Case I:
        TreeNode* val = findNode(root->left, target);
        if (val) return val;

        return findNode(root->right, target);
    }

};