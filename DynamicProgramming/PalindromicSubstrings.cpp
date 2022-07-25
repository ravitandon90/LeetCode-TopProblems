// Problem: https://leetcode.com/problems/palindromic-substrings/

#include <string>
#include <unordered_map>

using namespace std;

class PalindromicSubstrings {
private:
	string ToString(int i, int j) {
		return std::to_string(i) + "," + std::to_string(j);
	}

public:
	int countSubstrings(string s) {
		unordered_map<string, bool> memo;
		int result = 0;
		for (int len = 0; len <= s.size(); ++len) {
			for (int index = 0; index <= (s.size() - len); ++index) {
				bool isPalindrome = false;
				const string key = ToString(len, index);
				// All strings of length = 0 are palindromes by default.
				if (len == 0) {
					memo[key] = true;
					continue;
				}
				// All strings of length = 1 are palindromes by default.
				if (len == 1) {
					isPalindrome = true;
				} else {
					// IsPalindrome(index, len) = IsPalindrome(index + 1, len -2) && s[index] == s[index + len]
					isPalindrome = memo[ToString(len - 2, index + 1)] && (s[index] == s[index + len - 1]);
				}
				if (isPalindrome) {
					++result;
				}
				memo[key] = isPalindrome;
			}
		}
		return result;
	}
};