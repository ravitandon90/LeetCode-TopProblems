// Problem: https://leetcode.com/problems/swap-nodes-in-pairs/
// Definition for singly-linked list.
struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class SwapNodesInPairs {
public:
   ListNode* swapPairs(ListNode* head) {
      if (head == nullptr || head->next == nullptr) return head;
      ListNode* curr = head;
      ListNode* next = curr->next;
      curr->next = swapPairs(next->next);
      next->next = curr;
      return next;
   }
};