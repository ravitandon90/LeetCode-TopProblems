// Problem: https://leetcode.com/problems/reverse-vowels-of-a-string/

#include <string>

using namespace std;

class ReverseVowels {
public:
    string reverseVowels(string s) {
        int lo = 0, hi = s.size() - 1;
        while (lo < hi) {
            while (hi > lo && not IsVowel(tolower(s[hi]))) --hi;
            while (lo < hi && not IsVowel(tolower(s[lo]))) ++lo;
            if (lo >= hi) break;
            swap(s, lo, hi);
            --hi; ++lo;
        }
        return s;
    }

private:
    bool IsVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

    void swap(string& s, int l, int r) {
        char tmp = s[l];
        s[l] = s[r];
        s[r] = tmp;
    }
};