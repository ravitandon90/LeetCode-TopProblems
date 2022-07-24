// Problem: https://leetcode.com/problems/word-pattern/

#include <string>
#include <stringstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class WordPattern {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> m1;
        unordered_map<string, char> m2;
        vector<string> words = getWords(s);
        if (words.size() != pattern.size()) return false;

        // Pattern ---> String Of Words
        for (int i = 0; i < pattern.size(); ++i) {
            char ch = pattern.at(i);
            if (m1.find(ch) == m1.end()) {
                m1[ch] = words.at(i);
            } else {
                if (m1[ch] != words.at(i)) return false;
            }
        }
        // String Of Words --> Pattern
        for (int i = 0; i < words.size(); ++i) {
            string word = words.at(i);
            if (m2.find(word) == m2.end()) {
                m2[word] = pattern.at(i);
            } else {
                if (m2[word] != pattern.at(i)) return false;
            }
        }
        return true;
    }
    
private:
    vector<string> getWords(string s) {
        std::stringstream ss(s);
        std::istream_iterator<std::string> begin(ss);
        std::istream_iterator<std::string> end;
        std::vector<std::string> vstrings(begin, end);
        return vstrings;
    }
};