// Problem-Link: https://leetcode.com/problems/path-sum/
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class PathSum {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;
        if (targetSum == root->val && isLeaf(root)) return true;
        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }

private:
    bool isLeaf(TreeNode* node) {
        if (node == nullptr) return false;
        return node->left == node-> right && node->left == nullptr;
    }
};