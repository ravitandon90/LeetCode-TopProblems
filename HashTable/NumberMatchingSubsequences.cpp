// Problem: https://leetcode.com/problems/number-of-matching-subsequences/

#include <string>
#include <vector>

using namespace std;

class NumberMatchingSubsequences {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        vector<const char*> waiting[128];
        for (auto &w : words)
            waiting[w[0]].push_back(w.c_str());
        for (char c : S) {
            auto advance = waiting[c];
            waiting[c].clear();
            for (auto it : advance)
                waiting[*++it].push_back(it);
        }
        return waiting[0].size();
    }
};