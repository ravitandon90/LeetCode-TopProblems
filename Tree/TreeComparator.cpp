// https://leetcode.com/problems/same-tree/
// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class TreeComparator {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p == nullptr || q == nullptr) {
			return p == q;
		}
		if (p->val != q->val) return false;
		return
		    isSameTree(p->left, q->left) &&
		    isSameTree(p->right, q->right);
	}
};