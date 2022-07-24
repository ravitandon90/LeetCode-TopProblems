// Problem: https://leetcode.com/problems/add-two-numbers/
// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class TwoNumbersList {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* curr1 = l1;
		ListNode* curr2 = l2;
		ListNode* result = nullptr;
		ListNode* prevNode = nullptr;
		int carry_over = 0;
		while (true) {
			int sum = carry_over;
			if (curr1 != nullptr) { sum += curr1->val; curr1 = curr1->next; }
			if (curr2 != nullptr) { sum += curr2->val; curr2 = curr2->next; }
			carry_over = sum / 10;
			if (sum >= 10) sum -= 10;
			ListNode* newNode = new ListNode(sum);
			if (result == nullptr) result = newNode;
			else prevNode->next = newNode;
			prevNode = newNode;
			if (curr1 == nullptr && curr2 == nullptr) {
				if (carry_over == 1) {
					ListNode* newNode = new ListNode(1);
					if (result == nullptr) result = newNode;
					else prevNode->next = newNode;
				}
				break;
			}
		}
		return result;
	}
};