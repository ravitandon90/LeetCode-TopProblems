// Problem: https://leetcode.com/problems/number-of-good-ways-to-split-a-string/

#include <string>

using namespace std;

class GoodSplits {
public:
    int numSplits(string s) {
        int chars[2]; // 0 - left, 1 - right.
        chars[0] = 0;
        chars[1] = numUnique(s);
        int ch_count[26][2]; // 0 - left, 1 - right.
        for (int i = 0; i < 26; ++i) {
            ch_count[i][0] = 0;
            ch_count[i][1] = 0;
        }
        for (char ch : s) ch_count[ch - 'a'][1]++;                
        int count = 0; // Indicates the number of good splits.        
        for (char ch : s) {
            // New character added to left.
            ch_count[ch - 'a'][0]++;
            if (ch_count[ch - 'a'][0] == 1) ++chars[0];
            // New character deleted from right.
            ch_count[ch - 'a'][1]--;
            if (ch_count[ch - 'a'][1] == 0) --chars[1];
            if (chars[0] == chars[1]) ++count;
        }
        return count;
    }
    
private:    
    int numUnique(const string& s) {
        int uniques = 0;
        int ch_count[26];
        for (int i = 0; i < 26; ++i) ch_count[i] = 0;                    
        for (char ch : s) {
            ch_count[ch - 'a']++;
            if (ch_count[ch - 'a'] == 1) ++uniques;


        }
        return uniques;
    }
};