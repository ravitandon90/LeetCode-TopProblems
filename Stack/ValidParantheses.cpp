#include<string>
#include<stack>

using namespace std;

class ValidParantheses {
public:
    bool isValid(string s) {
      stack<char> s_stack;
      for (int index = 0; index < s.size(); ++index) {
          char ch = s[index];
          if (ch == '(' || ch == '{' || ch == '[') {
              s_stack.push(ch);              
          } else if (ch == ')' || ch == '}' || ch == ']') {
              if (s_stack.empty()) return false;
              char c2 = s_stack.top(); s_stack.pop();
              if (not match(c2, ch)) return false;
          }
      }
      return s_stack.empty();
    }
    
    bool match(char c1, char c2) {
        if (c1 == '(') return c2 == ')';
        if (c1 == '{') return c2 == '}';
        if (c1 == '[') return c2 == ']';
        return true;
    }
};