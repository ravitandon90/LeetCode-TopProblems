// Problem: https://leetcode.com/problems/rotated-digits/

class RotatedDigits {
public:
    int rotatedDigits(int n) {
        int count[10000 + 1];
        bool dp[10000 + 1];
        bool valid[10000 + 1];
        memset(count, 0, sizeof(count));
        memset(dp, false, sizeof(dp));
        memset(valid, false, sizeof(valid));

        dp[0] = false; valid[0] = true;
        dp[1] = false; valid[1] = true;
        dp[2] = true; count[2] = 1; valid[2] = true;
        dp[3] = false; count[3] = 1; // Not valid
        dp[4] = false; count[4] = 1; // Not valid
        dp[5] = true; count[5] = 2; valid[5] = true;
        dp[6] = true; count[6] = 3; valid[6] = true;
        dp[7] = false; count[7] = 3; // Not valid
        dp[8] = false; count[8] = 3; valid[8] = true;
        dp[9] = true; count[9] = 4; valid[9] = true;

        for (int i = 10; i <= n; ++i) {
            // isGood[n] = isGood[n/10] && isGood[n - 10*n/10]
            if (valid[i / 10] && valid[i - (i / 10 * 10)]) {
                dp[i] = dp[i / 10] || dp[i - (i / 10 * 10)];
                valid[i] = true;
            }
            if (dp[i]) {
                count[i] = count[i - 1] + 1;
            } else {
                count[i] = count[i - 1];
            }
        }
        return count[n];
    }
};