// Problem-Link: https://leetcode.com/problems/invert-binary-tree/

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

class InvertTree {
	TreeNode* invertTree(TreeNode* root) {
		if (root == nullptr) return nullptr;
		if (root->left == nullptr && root->right == nullptr) return root;
		TreeNode* tmp = root->left;
		root->left = root->right;
		root->right = tmp;
		invertTree(root->left);
		invertTree(root->right);
		return root;
	}
};