// Problem: https://leetcode.com/problems/basic-calculator-ii/

#include <string>

using namespace std;

class BasicCalculator {
public:
    int calculate(string s) {
        // Ensuring that the expression always ends with a space.
        string exp = s + " ";
        int index = -1;
        stack<string> st;
        string curr_str;
        char ch = exp[0], prev = exp[0];
        while (index < (int)exp.size()) {
            ++index;
            prev = ch;
            ch = exp[index];
            if ((ch == ' ') || (isdigit(ch) != isdigit(prev))) {
                if (curr_str.size() > 0 && curr_str[0] != ' ') {
                    st.push(curr_str);
                    curr_str.clear();
                }
            }
            if (ch == '*' || ch == '/') {
                int n1 = stoi(st.top()); st.pop();
                int n2 = getNum(exp, index);
                st.push(to_string(evaluate(n1, n2, ch)));
                continue;
            }
            if (ch == '+' || ch == '-') {
                if (st.size() > 2) {
                    int n2 = stoi(st.top()); st.pop();
                    string op = st.top(); st.pop();
                    int n1 = stoi(st.top()); st.pop();
                    st.push(to_string(evaluate(n1, n2, op[0])));
                }
            }
            if (ch != ' ') curr_str.append(1, ch);
        }
        if (st.empty()) return 0;
        if (st.size() == 1) {
            return stoi(st.top());
        }
        int n2 = stoi(st.top()); st.pop();
        string op = st.top(); st.pop();
        int n1 = stoi(st.top()); st.pop();
        return evaluate(n1, n2, op[0]);
    }

    int getNum(string& exp, int& index) {
        string num_str = "";
        while (index < exp.size()) {
            char ch = exp[index];
            if (not isdigit(ch) && num_str.size() > 0) { --index; break; }
            if (isdigit(ch)) num_str.append(1, ch);
            ++index;
        }
        if (num_str.size() > 0) return stoi(num_str);
        return 0;
    }

    int evaluate(int in1, int in2, char op) {
        switch (op) {
        case '+': return in1 + in2;
        case '-': return in1 - in2;
        case '*': return in1 * in2;
        case '/': return in1 / in2;
        default: return 0;
        }
        return 0;
    }
};