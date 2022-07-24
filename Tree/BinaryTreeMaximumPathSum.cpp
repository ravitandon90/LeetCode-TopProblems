// Problem: https://leetcode.com/problems/binary-tree-maximum-path-sum/
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BinaryTreeMaximumPathSum {
public:
    int maxPathSum(TreeNode* root) {
        maxSum(root);
        return this->_msum;
    }

private:
    int maxSum(TreeNode* node) {
        // Handling the base-case.
        if (node == nullptr) return 0;

        // Max-sum through children node.
        int maxSumLeft = std::max(maxSum(node->left), 0);
        int maxSumRight = std::max(maxSum(node->right), 0);

        // Calculating the sum through the root-node.
        int node_sum = node->val + maxSumLeft + maxSumRight;
        if (node_sum > this->_msum) this->_msum = node_sum;

        // Returning the sum assuming this node is part of the path.
        return node->val + max(maxSumLeft , maxSumRight);
    }

    int _msum = INT_MIN;
};