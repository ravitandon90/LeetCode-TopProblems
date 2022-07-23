// Problem-Link: https://leetcode.com/problems/binary-tree-level-order-traversal/

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

class LevelOrderTraversal {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> result;
		queue<TreeNode*> q_odd;
		queue<TreeNode*> q_even;
		// Step-I: Initializing the Queue.
		if (root) q_odd.push(root);
		bool isOdd = true;

		// Step-II: Go through both the queues and drain them.
		while (q_odd.size() > 0 || q_even.size() > 0) {
			vector<int> curr;
			if (isOdd) {
				// Drain the odd queue.
				while (q_odd.size() > 0) {
					TreeNode* tmp = q_odd.front(); q_odd.pop();
					if (tmp->left) q_even.push(tmp->left);
					if (tmp->right) q_even.push(tmp->right);
					curr.push_back(tmp->val);
				}
				result.push_back(curr);
			} else {
				// Drain the even queue.
				while (q_even.size() > 0) {
					TreeNode* tmp = q_even.front(); q_even.pop();
					if (tmp->left) q_odd.push(tmp->left);
					if (tmp->right) q_odd.push(tmp->right);
					curr.push_back(tmp->val);
				}
				result.push_back(curr);
			}
			// Flipping the bit.
			isOdd = not isOdd;
		}
		return result;
	}
};