// Problem: https://leetcode.com/problems/ransom-note/

#include <string>

using namespace std;

class RansomNote {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int letters[26];
        memset(letters, 0, sizeof(letters));
        for (char ch : magazine) letters[ch - 'a']++;
        for (char ch : ransomNote) { 
            letters[ch - 'a']--; 
            if (letters[ch - 'a'] < 0) return false;
        }
        return true;
    }
};