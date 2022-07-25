// Problem: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

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

struct Element {
    Element(int v_level, int h_level, int val): v_level(v_level), h_level(h_level), val(val) {}
    Element(): v_level(1001), h_level(1001), val(1001) {}
    int v_level = 1001;
    int h_level = 1001;
    int val = 1001;
};

struct CompElement {
    bool operator()(const Element& l, const Element& r) {
        if (l.v_level != r.v_level) return l.v_level > r.v_level;
        else if (l.h_level != r.h_level) return l.h_level > r.h_level;
        return l.val > r.val;
    }
};

class VerticalOrderTraversal {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result;
        priority_queue<Element, vector<Element>, CompElement> t_queue;
        next(root, 0, 0, t_queue);
        Element prev;
        while (not t_queue.empty()) {
            Element curr = t_queue.top(); t_queue.pop();
            if (prev.v_level == curr.v_level) result.back().push_back(curr.val);
            else result.push_back({curr.val});
            prev = curr;
        }
        return result;
    }

private:
    void next(TreeNode* root, int v_level, int h_level,
              priority_queue<Element, vector<Element>, CompElement>& t_queue) {
        if (root == nullptr) return;
        t_queue.push(Element(v_level, h_level, root->val));
        next(root->left, v_level - 1, h_level + 1,  t_queue);
        next(root->right, v_level + 1, h_level + 1, t_queue);
    }
};