// Problem: https://leetcode.com/problems/first-unique-character-in-a-string/

#include <string>

using namespace std;

class FindUniqueCharacter {
public:
    int firstUniqChar(const string& s) {
        int c_map[26];
        for (int i = 0; i < 26; ++i) {
            c_map[i] = -1;
        }
        int c_index = -1;
        for (char ch : s) {
            ++c_index;
            int index = ch - 'a';
            if (c_map[index] == -1) c_map[index] = c_index;
            else if (c_map[index] > -1) c_map[index] = -2;
        }
        int ans = s.size();
        for (int i = 0; i < 26; ++i) {
            if (c_map[i] > -1) ans = min(ans, c_map[i]);
        }
        return ans == s.size() ? -1 : ans;
    }
};