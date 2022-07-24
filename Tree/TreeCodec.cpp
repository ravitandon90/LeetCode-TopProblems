// Problem-Link: https://leetcode.com/problems/serialize-and-deserialize-n-ary-tree/

#include<queue>
#include<string>

using namespace std;

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;
    
    Node() {}
    Node(int _val): val(_val) {}
    Node(int _val, vector<Node*> _children): val(_val), children(_children) {}
};

class TreeCodec {
public:
    // Returns the number in @str starting at @index.
    int getNum(string str, int start_index, int* size_num) {
        string str_num = "";
        for (int index = start_index; index < str.size(); ++index) {
            if (isdigit(str[index])) str_num += str[index];
            else break;
        }
        *size_num = str_num.size();
        return atoi(str_num.c_str());
    }

    // Encodes a tree to a single string.
    string serialize(Node* root) {
        if (root == nullptr) return "";
        queue<Node*> node_queue;
        node_queue.push(root);
        string out = "[" + to_string(root->val) + ", null,";
        while (node_queue.size() > 0) {
            Node* curr = node_queue.front();
            node_queue.pop();
            vector<Node*> children = curr->children;
            for (int index = 0; index < children.size(); ++index) {
                node_queue.push(children[index]);
                out += to_string(children[index]->val) + ",";
            }
            out += std::string("null") + std::string(",");
        }
        out[out.size() - 1] = ']';
        return out;
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        if (data.size() == 0) return nullptr;
        Node* root = nullptr;
        Node* parent = nullptr;
        queue<Node*> node_queue;
        for (int index = 0; index < data.size(); ++index)  {
            if (isdigit(data[index])) {
                int size_num = 0;
                int num = getNum(data, index, &size_num);
                Node* newNode = new Node(num);
                if (root == nullptr) root = newNode;
                else parent->children.push_back(newNode);
                node_queue.push(newNode);
                index += size_num;
            } else if (data[index] == 'n') {
                // Handling the case of null.
                index += 4;
                if (node_queue.size() > 0) {
                    parent = node_queue.front();
                    node_queue.pop();
                }
            }
        }
        return root;
    }
};