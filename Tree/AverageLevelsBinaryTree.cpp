// Problem: https://leetcode.com/problems/average-of-levels-in-binary-tree/

#include <queue>
#include <vector>

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

class AverageLevelsBinaryTree {
public:
	vector<double> averageOfLevels(TreeNode* root) {
		queue<TreeNode*> odd;
		queue<TreeNode*> even;
		vector<double> result;
		odd.push(root);
		TreeNode* curr = nullptr;
		double sum = 0; int count = 0;
		while (not odd.empty() || not even.empty()) {
			while (not odd.empty()) {
				curr = odd.front(); odd.pop();
				if (curr == nullptr) continue;
				sum += curr->val;
				++count;
				even.push(curr->left);
				even.push(curr->right);
			}
			if (count > 0) result.push_back(sum / (double)count);
			sum = 0; count = 0;
			while (not even.empty()) {
				curr = even.front(); even.pop();
				if (curr == nullptr) continue;
				odd.push(curr->left);
				odd.push(curr->right);
				sum += curr->val;
				++count;
			}
			if (count > 0) result.push_back(sum / (double)count);
			sum = 0; count = 0;
		}
		return result;
	}
};