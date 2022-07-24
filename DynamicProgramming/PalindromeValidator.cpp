//Problem: https://leetcode.com/problems/valid-palindrome-ii/
#include<string>

using namespace std;

class PalindromeValidator {
public:
    bool validPalindrome(string s) {
        return validPalindromeInt(s, 0, s.size() - 1, 1);
    }

private:
    bool validPalindromeInt(string s, int start, int end, int count) {
        while (start < end && s[start] == s[end]) {
            ++start; 
            --end;
        }
        if (start >= end) return true;
        if (count <= 0) return false;
        return validPalindromeInt(s, start + 1, end, count - 1) || validPalindromeInt(s, start, end - 1, count - 1);
    }
};