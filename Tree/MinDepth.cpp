// Problem: https://leetcode.com/problems/minimum-depth-of-binary-tree/
// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class MinDepth {
public:
	int minDepth(TreeNode* root) {
		if (root == nullptr) return 0;
		if (root->left == nullptr && root->right == nullptr) return 1;
		int min_depth = INT_MAX;
		if (root->left != nullptr) min_depth = min(min_depth, minDepthUtil(root->left));
		if (root->right != nullptr) min_depth = min(min_depth, minDepthUtil(root->right));
		return 1 + min_depth;
	}

	int minDepthUtil(TreeNode* root) {
		if (root->left == nullptr && root->right == nullptr) return 1;
		if (root->left == nullptr) return 1 + minDepthUtil(root->right);
		if (root->right == nullptr) return 1 + minDepthUtil(root->left);
		return 1 + min(minDepthUtil(root->left), minDepthUtil(root->right));
	}
};