// Problem: https://leetcode.com/problems/word-break-ii/

#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<string>

using namespace std;

class WordBreakII {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // Step-I: Updating the internal dictionary.
        for (int index = 0; index < wordDict.size(); ++index) {
            this->_dict.insert(wordDict[index]);
        }

        // Step-II: Triggering the DP.
        vector<vector<string>> result = wordBreakDP(s);

        // Step III: Chain up words together.
        vector<string> output;
        for (int i = 0; i < result.size(); ++i) {
            string s;
            for (int j = 0; j < result[i].size(); ++j) {
                s += result[i][j] + " ";
            }
            // Trimming from the end to erase the empty space.
            if (s.size() > 0) s.erase(s.size() - 1, 1);
            output.push_back(s);
        }
        return output;
    }

private:
    vector<vector<string>> wordBreakDP(string s) {
        // Case - I: Base case. Empty string.
        if (s.size() == 0) {
            vector<vector<string>> emp_result;
            emp_result.push_back({});
            this->_memo[s] = emp_result;
        }

        // Case-II: This is already memoized.
        if (this->_memo.find(s) != this->_memo.end()) return this->_memo[s];

        // Case-III: This is not yet memoized.
        for (int end_index = 0; end_index < s.size(); ++end_index) {
            string word = s.substr(0, end_index + 1);
            if (this->_dict.find(word) != this->_dict.end()) {
                string restWord = s.substr(word.size());
                vector<vector<string>> result = wordBreakDP(restWord);
                for (int i = 0; i < result.size(); ++i) {
                    result[i].insert(result[i].begin(), word);
                    this->_memo[s].push_back(result[i]);
                }
            }
        }
        return this->_memo[s];
    }

    unordered_map<string, vector<vector<string>>> _memo;
    unordered_set<string> _dict;
};