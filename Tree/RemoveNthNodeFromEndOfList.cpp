// Problem: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class RemoveNthNodeFromEndOfList {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p1 = head;
        ListNode* p2 = p1;
        int count = 0;
        // Maintaining a delta of n between p1 & p2.
        while (count < n) {
            p2 = p2->next;
            ++count;
        }
        // Moving p2 to the end of the list.
        while (p2 && p2->next) {
            p1 = p1->next;
            p2 = p2->next;
        }
        ListNode* tmp = p1->next;
        p1->next = tmp->next;
        tmp = nullptr;
        return head;
    }
};