// Problem: https://leetcode.com/problems/increasing-order-search-tree/
// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class IncreasingOrderSearchTree {
public:
	TreeNode* increasingBST(TreeNode* root) {
		if (root == nullptr) return root;
		TreeNode* leftTree = root;
		if (root->left != nullptr) {
			leftTree = increasingBST(root->left);
			TreeNode* rightMostNode = leftTree;
			while (rightMostNode->right != nullptr) rightMostNode = rightMostNode->right;
			rightMostNode->right = root;
			root->left = nullptr;
		}
		if (root->right != nullptr) root->right = increasingBST(root->right);
		return leftTree;
	}
};