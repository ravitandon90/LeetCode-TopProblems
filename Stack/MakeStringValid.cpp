// Problem: https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/

#include<stack>
#include<string>

using namespace std;

class MakeStringValid {
public:
    string minRemoveToMakeValid(string s) {
        stack<char> s_stack;
        string output = "";
        // Forward Pass
        for (int i = 0; i < s.size(); ++i) {
            char ch = s[i];
            if (ch == ')') {
                if (s_stack.empty()) continue;
                s_stack.pop();
            }
            if (ch == '(') s_stack.push(ch);
            output.append(1, ch);
        }
        while (not s_stack.empty()) s_stack.pop();
        vector<int> to_erase;
        // Backward Pass
        for (int i = output.size() - 1; i >= 0; --i) {
            char ch = output[i];
            if (ch == '(') {
                if (s_stack.empty()) to_erase.push_back(i);
                else s_stack.pop();
            } else if (ch == ')') {
                s_stack.push(ch);
            }
        }
        for (int i = 0; i < to_erase.size(); ++i) {
            output.erase(to_erase[i], 1);
        }
        return output;
    }
};