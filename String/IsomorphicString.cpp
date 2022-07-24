// Problem: https://leetcode.com/problems/isomorphic-strings/

#include <string>

using namespace std;

class IsomorphicString {
public:
    bool isIsomorphic(const string& s, const string& t) {
        char lm[256];
        bool seen_s[256];
        bool seen_t[256];
        memset(seen_s, false, sizeof(seen_s));
        memset(seen_t, false, sizeof(seen_t));
        for (int idx = 0; idx < s.size(); ++idx) {
            char ch_s = s[idx];
            char ch_t = t[idx];
            if (seen_s[ch_s]) { 
                if (lm[ch_s] != ch_t) return false; 
            } else {
                if (seen_t[ch_t]) return false;
                lm[ch_s] = ch_t;
                seen_s[ch_s] = true;
                seen_t[ch_t] = true;
            }
        }
        return true;
    }
};