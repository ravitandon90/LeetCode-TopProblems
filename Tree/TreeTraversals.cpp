// Problem-Link: https://leetcode.com/problems/binary-tree-preorder-traversal/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class PreOrderTraversal {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		stack<TreeNode*> st;
		vector<int> result;
		if (root) st.push(root);
		while (st.size() > 0) {
			TreeNode* tmp = st.top(); st.pop();
			result.push_back(tmp->val);
			if (tmp->right) st.push(tmp->right);
			if (tmp->left) st.push(tmp->left);
		}
		return result;
	}
};