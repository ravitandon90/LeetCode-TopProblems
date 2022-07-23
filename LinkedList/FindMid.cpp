// Problem-Link: https://leetcode.com/problems/middle-of-the-linked-list/
// Definition for singly-linked list.
struct ListNode {
 int val;
 ListNode *next;
 ListNode() : val(0), next(nullptr) {}
 ListNode(int x) : val(x), next(nullptr) {}
 ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class FindMid {
public:
    ListNode* middleNode(ListNode* head) {
        if (head == nullptr) return head;
        ListNode* curr = head;
        ListNode* twoStep = head->next;
        while (twoStep && twoStep->next) {
            curr = curr->next;
            twoStep = twoStep->next->next;
        }
        if (twoStep == nullptr) return curr;
        return curr->next;
    }
};