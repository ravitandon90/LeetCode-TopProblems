//Problem: https://leetcode.com/problems/diameter-of-binary-tree/
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BinaryTreeDiameter {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;
        int diameter = 0;
        diameter = max(diameter, (1 + getHeight(root->left) + 1 + getHeight(root->right)));
        diameter = max(diameter, diameterOfBinaryTree(root->left));
        diameter = max(diameter, diameterOfBinaryTree(root->right));
        return diameter;
    }

private:
    int getHeight(TreeNode* root) {
        if (root == nullptr) return -1;
        int height = 0;
        if (root->left != nullptr) height = max(height, 1 + getHeight(root->left));
        if (root->right != nullptr) height = max(height, 1 + getHeight(root->right));
        return height;
    }
};