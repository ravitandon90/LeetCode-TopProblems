// Problem: https://leetcode.com/problems/longest-uncommon-subsequence-i/submissions/

#include <string>

using namespace std;

class LongestUncommonSubsequence {
public:
    int findLUSlength(string a, string b) {
        if (a.size() != b.size()) return getMax(a.size(), b.size());
        if (a == b) return -1;
        return a.size();
    }
private:
    int getMax(int a, int b) {
        if (a > b) return a;
        return b;
    }
};