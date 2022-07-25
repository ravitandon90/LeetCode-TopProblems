// Problem: https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/

#include <string>

using namespace std;

class ValidParantheses {
public:
    int minAddToMakeValid(string s) {
        int bal = 0;
        int ans = 0;
        for (char ch : s) {
            if (ch == '(') ++bal;
            else --bal;
            if (bal == -1) { ++ans; ++bal; }
        }
        return ans + bal;
    }
};