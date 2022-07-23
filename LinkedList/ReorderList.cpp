// Problem-Link: https://leetcode.com/problems/reorder-list/
// Definition for singly-linked list.

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class ReorderList {
public:
    void reorderList(ListNode* head) {
        // Base Case: Handling 1 element.
        if (head == nullptr || head->next == nullptr) return;
        // Step-I: Find the middle element.
        ListNode* mid = middleNode(head);

        // Step-II: Set prev to mid as nullptr.
        ListNode* curr = head;
        while (curr->next != mid) {
            curr = curr->next;
        }
        curr->next = nullptr;

        // Step-III: Reverse mid, end.
        ListNode* mid_reversed = reverseList(mid);

        // Step-IV: Merge two lists.
        mergeLists(head, mid_reversed);

    }

private:
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

    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while (curr) {
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        return prev;
    }

    void mergeLists(ListNode* first, ListNode* second) {
        ListNode* f = first;
        ListNode* s = second;
        while (f && s) {
            ListNode* tmp1 = f->next;
            ListNode* tmp2 = s->next;
            f->next = s;
            if (tmp1) {
                s->next = tmp1;
            }
            f = tmp1;
            s = tmp2;
        }
    }
};