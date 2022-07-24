#include<stack>
#include<string>

using namespace std;

class MakeStringGreat {
public:
    string makeGood(string s) {
        string out = "";
        stack<char> s_stack;
        for (int index = 0; index < s.size();  ++index) {
            if (s_stack.empty()) {
                s_stack.push(s[index]);
                continue;
            }
            char c1 = s_stack.top();
            if (isBad(c1, s[index])) {
                s_stack.pop();
            } else {
                s_stack.push(s[index]);
            }
        }
        while (not s_stack.empty()) {
            out = string(1, s_stack.top()) + out;
            s_stack.pop();
        }
        return out;
    }

private:
    bool isBad(char c1, char c2) {
        return ((c1 != c2) && (tolower(c1) == tolower(c2)));
    }
};