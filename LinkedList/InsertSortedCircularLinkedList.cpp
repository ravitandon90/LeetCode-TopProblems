// Problem: https://leetcode.com/problems/insert-into-a-sorted-circular-linked-list/

// Definition for a Node.
struct Node {
    int val;
    Node* next;

    Node() {}
    Node(int _val): val(_val), next(NULL) {}
    Node(int _val, Node* _next): val(_val), next(_next) {}    
};

class InsertSortedCircularLinkedList {
public:
    Node* insert(Node* head, int insertVal) {
        Node* newNode = new Node(insertVal);    
        // Case-I: Head is null.
        if (head == nullptr) { head = newNode;  newNode->next = newNode; }                  
        // Case-II: Single node.
        else if (head->next == head) {
            head->next = newNode;
            newNode->next = head;
        } else {
            // Use 2-Pointer approach.
            Node* curr = head->next;
            Node* prev = head;
            while (newNode->next == nullptr) {  
                //cout << "P, C=" << prev->val << "," << curr->val << endl;
                // Case-III: Element already exists.     
                if (curr->val == insertVal) {
                    prev->next = newNode;
                    newNode->next = curr;                    
                }
                // Case-IV: Element is a valid mid-entry.
                // Eg. [1, 3, 5], [2]
                else if (prev->val <= insertVal && insertVal <= curr->val) {
                    prev->next = newNode;
                    newNode->next = curr;                    
                }
                // Case V: Element is the highest number.
                // Eg. [1, 3, 5], [6]
                // curr = 1, prev = 5
                else if (prev->val <= insertVal && curr->val <= insertVal && curr->val < prev->val) {
                    prev->next = newNode;
                    newNode->next = curr;
                }
                // Case VI: Element is the smallest number.
                // Eg. [1, 3, 5], [0]
                // curr = 1, prev = 5
                else if (insertVal <= prev->val  && insertVal <= curr->val && curr->val < prev->val) {
                    prev->next = newNode;
                    newNode->next = curr;
                }
                 // Case VII: Insert anywhere.
                 else if (curr == head) {
                    prev->next = newNode;
                    newNode->next = curr;                    
                 }
                prev = curr;
                curr = curr->next;
            }            
        }
        
        // End: Return head.
        return head;
    }
};