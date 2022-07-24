// Problem: https://leetcode.com/problems/intersection-of-two-linked-lists/

#include <stack>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class LinkedListIntersection {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        stack<ListNode*> s1 = toStack(headA);
        stack<ListNode*> s2 = toStack(headB);
        ListNode* intersection = nullptr;
        while (not s1.empty() && not s2.empty()) {
            ListNode* n1 = s1.top(); s1.pop();
            ListNode* n2 = s2.top(); s2.pop();
            if (n1 == n2) intersection = n1;
            else break;
        }
        return intersection;
    }

    stack<ListNode*> toStack(ListNode* head) {
        stack<ListNode*> st;
        ListNode* curr = head;
        while (curr != nullptr) {
            st.push(curr);
            curr = curr->next;
        }
        return st;
    }
};