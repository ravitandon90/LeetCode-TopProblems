// Problem: https://leetcode.com/problems/count-sorted-vowel-strings/

#include <vector>

using namespace std;

class CountSortedVowelStrings {
public:
    int countVowelStrings(int n) {
        vector<vector<int>> memo;
        for (int i = 0; i <= n; ++i) {
            memo.push_back({});
            for (int j = 0; j <= 5; ++j) {
                int num = -1;
                if (i == 0 || j == 0) num = 0;
                else if (i == 1) num = j;
                else if (j == 1) num = 1;
                memo.back().push_back(num);
            }
        }
        return countVowelUtil(n, 5, memo);
    }

private:
    int countVowelUtil(int n, int vowels, vector<vector<int>>& memo) {
        if (memo[n][vowels] != -1) return memo[n][vowels];
        memo[n][vowels] = countVowelUtil(n - 1, vowels, memo) + countVowelUtil(n, vowels - 1, memo);
        return memo[n][vowels];
    }
};