// Problem: https://leetcode.com/problems/closest-binary-search-tree-value/
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class ClosestBinarySearchTreeValue {
public:
    int closestValue(TreeNode* root, double target) {
        double delta = abs(target - (double)root->val);
        int clValue = root->val;
        if (root->left != nullptr) {
            int l = closestValue(root->left, target);
            if (abs((double)l - target) < delta) {
                clValue = l;
                delta = abs((double)l - target);
            }
        }
        if (root->right != nullptr) {
            int r = closestValue(root->right, target);
            if (abs((double)r - target) < delta) {
                clValue = r;
                delta = abs((double)r - target);
            }
        }
        return clValue;
    }
};