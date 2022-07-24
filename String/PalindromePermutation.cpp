// Problem: https://leetcode.com/problems/palindrome-permutation/

#include <string>

using namespace std;

class PalindromePermutation {
public:
	bool canPermutePalindrome(string s) {
		bool sign[26];
		int odd = 0;
		memset(sign, false, sizeof(sign));
		for (char ch : s) {
			sign[ch - 'a'] = not sign[ch - 'a'];
		}
		for (int i = 0; i < 26; ++i) {
			if (sign[i]) ++odd;
		}
		if (odd > 1) return false;
		if (odd == 1) return (s.size() % 2 == 1);
		return true;
	}
};