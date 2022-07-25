// Problem: https://leetcode.com/problems/count-substrings-that-differ-by-one-character/

#include <string>

using namespace std;

class CountDifferSubstrings {
public:
    int countSubstrings(string s, string t) {
        int dp[s.size() + 1][t.size() + 1][2];
        for (int i = 0; i <= s.size(); ++i) {
            for (int j = 0; j <= t.size(); ++j) {
                dp[i][j][0] = 0;
                dp[i][j][1] = 0;
            }
        }
        int sum = 0;
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 1; j <= t.size(); ++j) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j][0] = dp[i-1][j-1][0] + 1;
                    dp[i][j][1] = dp[i-1][j-1][1];
                } else {
                     dp[i][j][0] = 0;
                     dp[i][j][1] = dp[i-1][j-1][0] + 1;
                }
                sum += dp[i][j][1];
            }
        }
        return sum;
    }
};