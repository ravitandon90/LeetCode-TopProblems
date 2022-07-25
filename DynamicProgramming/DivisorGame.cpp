// Problem: https://leetcode.com/problems/divisor-game/

class DivisorGame {
public:
	bool divisorGame(int n) {
		if (n == 1) return false;
		if (n == 2) return true;
		bool dp[n + 1];
		for (int i = 0; i <= n; ++i) dp[i] = false;
		dp[2] = true;
		for (int i = 3; i <= n; ++i) {
			for (int j = i - 1; j > 0; --j) {
				int x = i - j;
				if ((i % x) != 0) continue;
				if (!dp[j]) { dp[i] = true; break; }
			}
		}
		return dp[n];
	}
};