// Problem-Link: https://leetcode.com/problems/subtree-of-another-tree/
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class SubtreeCheck {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (isIdentical(root, subRoot)) return true;
        if (root) {
            if (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot)) return true;
        }
        return false;
    }

private:
    bool isIdentical(TreeNode* first, TreeNode* second) {
        if (first == nullptr && second == nullptr) return true;
        if (first != nullptr && second != nullptr) {
            if (first->val == second->val) {
                return
                    isIdentical(first->left, second->left) &&
                    isIdentical(first->right, second->right);
            }
        }
        return false;
    }
};