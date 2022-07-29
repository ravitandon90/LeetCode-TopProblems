// Problem: https://leetcode.com/problems/palindrome-linked-list/

#include <stack>

using namespace std;

// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class PalindromLinkedList {
public:
    bool isPalindrome(ListNode* head) {
       // Step-I: Find size.
       int size = 0;
       ListNode* curr = head;
       while (curr != nullptr) {
           ++size;
           curr = curr->next;
       }
        
        // Step-II: Push elements in the stack.
        stack<ListNode*> st;
        int mid = size/2;
        curr = head;
        for (int i = 0; i < size; ++i, curr = curr->next) {
            if (((size %2) == 1) && (i == mid)) continue;
            else if (i < mid) st.push(curr);
            else {
                ListNode* node = st.top();
                st.pop();
                if (node->val != curr->val) return false;
            }            
        }
        return true;
    }
};