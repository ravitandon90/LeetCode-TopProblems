#include<iostream>

using namespace std;

// Link to the problem: https://leetcode.com/problems/design-skiplist/

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */

struct Node {
  Node(Node* right, Node* down, int value) {
    this->right = right;
    this->down = down;
    this->value = value;
  }
  Node* right;
  Node* down;
  int value;
};

class Skiplist {
private:
  Node* head;

public:
  Skiplist() { head = new Node(nullptr, nullptr, -1); }

  void add(int num) {
    Node* p = head;
    vector<Node*> insertPoints;
    while (p) {
      while(p->right and p->right->value < num) p = p->right;
      insertPoints.push_back(p);
      p = p->down;
    }
    
    bool insertUp = true;
    Node* downNode = nullptr;
    while(insertUp and insertPoints.size() > 0) {
      p = insertPoints.back(); 
      insertPoints.pop_back();      
      
      p->right = new Node(p->right, downNode, num);
      downNode = p->right;

      insertUp = (rand() & 1) == 0;
    }

    if (insertUp) {
      p = new Node(new Node(nullptr, downNode, num), head, -1);
     }
}
  
  bool search(int num) {
    Node* p = head;
    while(p) {
      while(p->right and p->right->value < num) p = p->right;
      if (!p->right or p->right->value > num) p = p->down;
      else return true;
    }
    return false;
  }
  
  bool erase(int num) {
    Node* p = head;
    bool seen = false;
    while(p) {
      while(p->right and p->right->value < num) p = p->right;
      if (!p->right or p->right->value > num) p = p->down;
      else {
        seen = true;
        Node* target = p->right;
        p->right = target->right;      
        p = p->down;
        delete target;
      }      
    }
    return seen;
  }
};
