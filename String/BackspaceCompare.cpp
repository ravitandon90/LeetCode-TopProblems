// Problem: https://leetcode.com/problems/backspace-string-compare/

#include <stack>
#include <string>

using namespace std;

class BackspaceCompare {
public:
    bool backspaceCompare(const string& s, const string& t) {
        stack<char> st_s, st_t;
        for (char ch : s) {
            if (ch == '#') { if (st_s.size() > 0) st_s.pop(); }
            else st_s.push(ch);
        }
        for (char ch : t) {
            if (ch == '#') { if (st_t.size() > 0) st_t.pop(); }
            else st_t.push(ch);
        }
        return st_s == st_t;
    }
};