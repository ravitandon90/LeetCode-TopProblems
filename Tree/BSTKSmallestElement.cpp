// Link to the problem: https://leetcode.com/problems/kth-smallest-element-in-a-bst/

#include<iostream>
#include<stack>

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

class BSTKSmallestElement {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        if (root) {
            if (root->right) st.push(root->right);
            root->right = nullptr;
            st.push(root);
            if (root->left) st.push(root->left);
            root->left = nullptr;
        }
        int rank = 0;
        while (st.size() > 0) {
            TreeNode* tmp = st.top(); st.pop();
            if (tmp->right == nullptr && tmp->left == nullptr) {
                // We have already seen this node, or this node is a leaf node.
                ++rank;
                if (rank == k) return tmp->val;
            } else {
                if (tmp->right) st.push(tmp->right);
                tmp->right = nullptr;
                st.push(tmp);
                if (tmp->left) st.push(tmp->left);
                tmp->left = nullptr;
            }
        }
        return -1;
    }
};