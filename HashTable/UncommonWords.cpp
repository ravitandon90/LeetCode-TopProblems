// Problem: https://leetcode.com/problems/uncommon-words-from-two-sentences/

using namespace std;

#include <vector>
#include <string>
#include <stringstream>

using namespace std;

class UncommonWords {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> result;
        unordered_map<string, int> words;
        string word;
        stringstream ss1(s1);
        stringstream ss2(s2);
        while(getline(ss1, word, ' ')) words[word]++;        
        while(getline(ss2, word, ' ')) words[word]++;
        unordered_map<string, int>::iterator it;
        for (it = words.begin(); it != words.end(); ++it) {
            if (it->second == 1) {
                result.push_back(it->first);
            }
        }
        return result;
    }
};