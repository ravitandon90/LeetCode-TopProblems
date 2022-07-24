// Problem: https://leetcode.com/problems/balanced-binary-tree/
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BalancedTreeValidator {
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;
        if ((abs(getHeight(root->left) - getHeight(root->right))) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }

private:
    int getHeight(TreeNode* root) {
        if (root == nullptr) return 0;
        return 1 + max(getHeight(root->left), getHeight(root->right));
    }
};