// Problem-Link: https://leetcode.com/problems/linked-list-cycle/
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class CycleDetector {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return false;
        ListNode* c1 = head;
        ListNode* c2 = head->next;
        while (c1 != c2) {
            if ((c1 == nullptr) || (c2 == nullptr) || (c2->next == nullptr)) break;
            c1 = c1->next;
            c2 = c2->next->next;
        }
        return c1 == c2;
    }
};