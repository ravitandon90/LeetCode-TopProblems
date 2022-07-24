// Problem: https://leetcode.com/problems/delete-node-in-a-linked-list/
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class DeleteNode {
public:
    void deleteNode(ListNode* node) {
        if (node == nullptr || node->next == nullptr) return;
        while (true) {
            swap(node, node->next);
            if (node->next->next == nullptr) {
                node->next = nullptr;
                break;
            }
            else node = node->next;
        }
    }

    void swap(ListNode* n1, ListNode* n2) {
        int tmp = n1->val;
        n1->val = n2->val;
        n2->val = tmp;
    }
};