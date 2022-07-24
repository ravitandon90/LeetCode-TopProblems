// Problem: https://leetcode.com/problems/length-of-last-word/

#include<string>

using namespace std;

class LastWordLength {
public:
  int lengthOfLastWord(string s) {
    int len = 0;
    for (int i = s.size() - 1; i >= 0; --i) {
      char ch = s[i];
      if (ch == ' ' && len == 0) continue;
      if (ch == ' ' && len > 0) return len;
      if (ch != ' ') ++len;
    }
    return len;
  }
};