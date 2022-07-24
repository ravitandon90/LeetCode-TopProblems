// Problem: https://leetcode.com/problems/merge-k-sorted-lists/

#include<vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct CompareNode {
    bool operator()(ListNode* l, ListNode* r) {
        return l->val > r->val;
    }
};

class MergeKSortedLists {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, CompareNode> pq;
        for (int i = 0; i < lists.size(); ++i) {
            ListNode* curr = lists.at(i);
            while (curr != nullptr) {
                pq.push(curr);
                curr = curr->next;
            }
        }
        ListNode* head = nullptr;
        ListNode* curr = nullptr;
        while (pq.size() > 0) {
            ListNode* tmp = pq.top(); pq.pop();
            if (head == nullptr) {
                head = tmp;
                curr = head;
            } else {
                curr->next = tmp;
                curr = curr->next;
            }
            curr->next = nullptr;
        }
        return head;
    }
};