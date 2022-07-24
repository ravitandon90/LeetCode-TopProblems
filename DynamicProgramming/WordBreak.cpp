// Problem: https://leetcode.com/problems/word-break/

#include<string>
#include<unordered_map>
#include<unordered_set>
#include<vector>

using namespace std;

class WordBreak {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		// Convert vector to set.
		unordered_set<string> wordSet;
		for (const auto& word : wordDict) wordSet.insert(word);
		unordered_map<int, bool> memo;
		return wordBreakWithMemo(s, 0, wordSet, memo);
	}

private:
	bool wordBreakWithMemo(const string& s, int start,
	                       const unordered_set<string>& wordSet, unordered_map<int, bool>& memo) {
		// End of the string, yes -> we have found a way to break the string.
		if (start == s.size()) return true;
		// If we have seen this pivot, then return the value;
		if (memo.find(start) != memo.end()) return memo[start];

		string curr = "";
		for (int i = start; i < s.size(); ++i) {
			curr.append(1, s.at(i));
			if (wordSet.find(curr) != wordSet.end()) {
				if (wordBreakWithMemo(s, i + 1, wordSet, memo)) {
					memo[start] = true;
					return true;
				}
			}
		}
		memo[start] = false;
		return false;
	}
};