#include<string>

using namespace std;

class IsSubsequence {
public:
    bool isSubsequence(string s, string t) {
        return isSubsequenceInternal(s, t, 0, 0);
    }

    bool isSubsequenceInternal(string s, string t, int s_start, int t_start) {
        if (s_start >= s.size()) return true;
        if (t_start >= t.size()) return false;
        if (s[s_start] == t[t_start]) return isSubsequenceInternal(s, t, s_start + 1, t_start + 1);
        return isSubsequenceInternal(s, t, s_start, t_start + 1);
    }
};