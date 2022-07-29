// Problem: https://leetcode.com/problems/minimum-distance-between-bst-nodes/

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class MinDistanceBSTTree {
public:
    int minDiffInBST(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr) return INT_MAX;
        int minDiff = root->val;
        if (root->left != nullptr) {
            minDiff = min(minDiff, minDiffInBST(root->left));
            minDiff = min(minDiff, abs(root->val - getMaxInBST(root->left)));
        }
        if (root->right != nullptr) {
            minDiff = min(minDiff, minDiffInBST(root->right));
            minDiff = min(minDiff, abs(root->val - getMinInBST(root->right)));
        }
        return minDiff;
    }

    int getMinInBST(TreeNode* root) {
        if (root->left == nullptr) return root->val;
        return getMinInBST(root->left);
    }

    int getMaxInBST(TreeNode* root) {
        if (root->right == nullptr) return root->val;
        return getMaxInBST(root->right);
    }
};