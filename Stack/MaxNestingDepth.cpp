// Problem: https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/
#include<stack>
#include<string>

using namespace std;

class MaxNestingDepth {
public:
    int maxDepth(string s) {
        stack<char> s_stack;
        int max_depth = 0;
        for (int i = 0; i < s.size(); ++i) {
            char ch = s[i];
            if (ch == '(') {
                s_stack.push(ch);
                max_depth = max(max_depth, (int)s_stack.size());
            }
            if (ch == ')') {
                s_stack.pop();
            }
        }
        return max_depth;
    }
};