// Problem: https://leetcode.com/problems/remove-invalid-parentheses/

#include<string>
#include<vector>

using namespace std;

class RemoveInvalidParentheses {
public:
    vector<string> removeInvalidParentheses(string s) {
        string expression;
        string s1 = trimBraces(s);
        this->recurse(s1, expression, 0, 0, 0, 0);
        return uniqify(this->_solutions);
    }

private:
    string trimBraces(string s) {
        string s1 = s;
        int index = s1.size() - 1;
        while (index >= 0) {
            char curr_ch = s1[index];
            if (curr_ch == ')') break;
            if (curr_ch == '(') s1.erase(index, 1);
            --index;
        }
        return s1;
    }

    vector<string> uniqify(const vector<string>& vec) {
        unordered_set<string> s;
        vector<string> vec_s;
        for (int i = 0; i < vec.size(); ++i) {
            if (s.find(vec[i]) == s.end()) {
                vec_s.push_back(vec[i]);
                s.insert(vec[i]);
            }
        }
        return vec_s;
    }

    void recurse(string s, string& expression, int index, int r_count, int l_count, int num_removals) {
        // Case-I: If this is the end of the string.
        if (index == s.size()) {
            // Check if this is a valid string.
            if (l_count == r_count) {
                // Reset, if the number of removals is less.
                if (num_removals < this->_min_removals) {
                    this->_min_removals = num_removals;
                    this->_solutions.clear();
                }
                // Update the solution set with the current solution.
                if (num_removals == this->_min_removals) {
                    this->_solutions.push_back(expression);
                }
            }
        } else {
            char curr_char = s.at(index);
            // Case-II: Skip over non-brackets.
            if (curr_char != '(' && curr_char != ')') {
                expression.append(1, curr_char);
                this->recurse(s, expression, index + 1, r_count, l_count, num_removals);
                expression.erase(expression.size() - 1 /* Index */, 1 /* Length */);
            } else {
                // Case-III: Delete a bracket and try.
                this->recurse(s, expression, index + 1, r_count, l_count, num_removals + 1);
                expression.append(1, curr_char);
                // Case-IV: Accept an opening brace.
                if (curr_char == '(') {
                    this->recurse(s, expression, index + 1, r_count, l_count + 1, num_removals);
                } else if (l_count > r_count) { // Case-V: Accept a closing brace.
                    this->recurse(s, expression, index + 1, r_count + 1, l_count, num_removals);
                }
                expression.erase(expression.size() - 1 /* Index */, 1 /* Length */);
            }
        }
    }

    int _min_removals = INT_MAX;
    vector<string> _solutions;

};