// Problem-Link: https://leetcode.com/problems/buddy-strings/

#include<string>

using namespace std;

class BuddyStringFinder {
public:
  bool buddyStrings(string s, string goal) {
    if (s.size() != goal.size()) return false;
    int count = 0;
    vector<char> chars_s, chars_goal;
    unordered_map<char, int> char_count;
    int max_char_len = 0;
    for (int i = 0; i < s.size(); ++i) {
      char_count[s[i]]++;
      if (max_char_len < char_count[s[i]]) {
        max_char_len = char_count[s[i]];
      }
      if (s[i] != goal[i]) {
        count++;
        chars_s.push_back(s[i]);
        chars_goal.push_back(goal[i]);
      }
      if (count > 2) break;
    }
    if (count == 2) {
      if ((chars_s.at(0) == chars_goal.at(1)) && (chars_s.at(1) == chars_goal.at(0))) {
        return true;
      }
    }
    if (count == 0) return max_char_len > 1;
    return false;
  }
};