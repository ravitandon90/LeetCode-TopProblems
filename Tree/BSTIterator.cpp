// Problem: https://leetcode.com/problems/binary-search-tree-iterator/
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        buildList(root);
        this->_pointer = -1;
    }

    int next() {
        if (not hasNext()) return -1;
        return this->_nums[++this->_pointer];
    }

    bool hasNext() {
        return (this->_pointer < (int)(this->_nums.size() - 1));
    }

private:
    void buildList(TreeNode* root) {
        if (root == nullptr) return;
        buildList(root->left);
        this->_nums.push_back(root->val);
        buildList(root->right);
    }

    int _pointer;
    vector<int> _nums;

};