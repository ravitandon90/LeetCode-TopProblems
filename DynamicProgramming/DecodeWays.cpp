// Problem: https://leetcode.com/problems/decode-ways/

#include <unordered_map>

using namespace std;

class DecodeWays {
public:
	int numDecodings(string s) { return numDecodingsWithMemo(s, 0); }
	
	int numDecodingsWithMemo(string s, int i) {
		// If you have reached the end of a string, then return 1 as success.
		if (i == s.size()) return 1;

		// String that starts with '0' has no decodings.
		if (s.at(i) == '0') return 0;

		// If you have reached the end of a string, then return 1 as success.
		if (i == (s.size() - 1)) return 1;

		// If you have seen the string in the past, return the string.
		if (memo.find(i) != memo.end()) return memo[i];

		// The number of decodings is sum of two cases.
		// Case I: Take one leading character out.
		// Case II: Take two leading characters out.
		int ans = numDecodingsWithMemo(s, i + 1);
		if (stoi(s.substr(i, 2)) <= 26) {
			ans += numDecodingsWithMemo(s, i + 2);
		}
		memo[i] = ans;
		return ans;
	}

private:
	unordered_map<int, int> memo;
};