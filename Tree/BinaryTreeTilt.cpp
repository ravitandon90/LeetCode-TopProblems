// Problem: https://leetcode.com/problems/binary-tree-tilt/
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BinaryTreeTilt {
public:
    int findTilt(TreeNode* root) {
        if (root == nullptr) return 0;
        int tilt = abs(findSum(root->left) - findSum(root->right));
        return tilt + findTilt(root->left) + findTilt(root->right);
    }

private:
    int findSum(TreeNode* root) {
        if (root == nullptr) return 0;
        return root->val + findSum(root->left) + findSum(root->right);
    }
};