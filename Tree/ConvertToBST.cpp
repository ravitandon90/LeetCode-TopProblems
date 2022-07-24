// Problem: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

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

class ConvertToBST {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return recurse(nums, 0, nums.size() - 1);
    }

    TreeNode* recurse(vector<int>& nums, int s, int e) {
        if (s > e) return nullptr;
        int mid = (s + e) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->right = recurse(nums, mid + 1, e);
        node->left = recurse(nums, s, mid - 1);
        return node;
    }
};