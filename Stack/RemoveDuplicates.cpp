// Problem: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

#include <stack>
#include <string>

using namespace std;

class RemoveDuplicates {
public:
	string removeDuplicates(const string& s) {
		stack<char> s_stack;
		string result;
		for (int i = 0; i < s.size(); ++i) {
			if (s_stack.empty()) s_stack.push(s[i]);
			else {
				if (s[i] == s_stack.top()) s_stack.pop();
				else s_stack.push(s[i]);

			}
		}
		while (!s_stack.empty()) {
			result.insert(result.begin(), s_stack.top());
			s_stack.pop();
		}
		return result;
	}
};