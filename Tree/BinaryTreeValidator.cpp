// Problem-Link: https://leetcode.com/problems/validate-binary-search-tree/
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BinaryTreeValidator {
public:
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;
        if (not isValidBST(root->left) || not isValidBST(root->right)) return false;
        // Condition I: Max(root->left) < root->val
        if (root->left) {
            int max_left = getMax(root->left);
            if (root->val <= max_left) return false;
        }
        // Condition II: Min(root->right) > root->val
        if (root->right) {
            int min_right = getMin(root->right);
            if (root->val >= min_right) return false;
        }
        return true;
    }

private:
    int getMin(TreeNode* root) {
        if (root->left != nullptr) return getMin(root->left);
        return root->val;
    }

    int getMax(TreeNode* root) {
        if (root->right != nullptr) return getMax(root->right);
        return root->val;
    }

};