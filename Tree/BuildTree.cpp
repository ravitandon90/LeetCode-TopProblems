#include<vector>

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

class BuildTree {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Step-I: Build inorder index map.
        unordered_map<int, int> inorder_map;
        int preorder_index = 0;
        for (int i = 0; i < inorder.size(); ++i) {
            inorder_map[inorder.at(i)] = i;
        }
        
        // Step-II: Recursively build the tree.
        return buildTreeInt(preorder, inorder, inorder_map, preorder_index, 0, inorder.size() - 1);
    }
    
    TreeNode* buildTreeInt(const vector<int>& preorder, const vector<int>& inorder,
                           const unordered_map<int, int>& inorder_map,
                           int& preorder_index, int start_inorder, int end_inorder) {
        
        // Base Case: No more roots left.
        if (preorder.size() == preorder_index) return nullptr;        
        
        // Step-I: Find root.
        int root_val = preorder.at(preorder_index++);
        TreeNode* root = new TreeNode(root_val);
        
        // Step-II: Get index in inorder.
        int index = inorder_map.at(root_val);
        
        if ((index < start_inorder) || (index > end_inorder)) {
            return nullptr;
        }
        
        // Step-III: Left subtree = [start_inorder, index - 1].
        if (start_inorder <= (index - 1)) {
            root->left = buildTreeInt(preorder, inorder, inorder_map, preorder_index, start_inorder, index - 1);
        }
        
        // Step-IV: Right subtree = [index + 1, end_inorder].
        if (end_inorder >= (index + 1)) {
            root->right = buildTreeInt(preorder, inorder, inorder_map, preorder_index, index + 1, end_inorder);
        }
        
        return root;
    }
};