// Problem-Link: https://leetcode.com/problems/check-if-word-equals-summation-of-two-words/

#include<string>

using namespace std;

class WordComparator {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        return toNum(firstWord) + toNum(secondWord) == toNum(targetWord);
    }
private:
    int toNum(string word) {
        int num = 0;
        for (int index = 0; index < word.size(); ++index) {
            char ch = word.at(index);
            int val = (int)(ch) - (int)('a');
            num = num * 10 + val;
        }
        return num;
    }
};